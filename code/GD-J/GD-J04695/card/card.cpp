#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int k=b[a[j]];k<j;k++){
					b[a[k]]=0;
				}
			}
			b[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(b[j]!=0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
