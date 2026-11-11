#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],b[300005],ans[300005];
	bool flag[500005];
	memset(b,0,sizeof(b));
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=n;i++)flag[i]=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=j;
			}else{
				for(int k=b[a[j]];k<j;k++){
					b[a[k]]=0;
					flag[k]=false;
				}
				b[a[j]]=j;
			}
		}
		for(int j=n;j>=i;j--){
			if(flag[j]==true){
				ans[a[j]]++;
			}
			flag[j]=true;
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
