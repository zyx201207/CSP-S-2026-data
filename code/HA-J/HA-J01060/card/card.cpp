#include <bits/stdc++.h>
using namespace std;
bool tong[300005];
int a[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(tong,0,sizeof(tong));
		int st[300005],tot=0;
		for(int j=i;j<=n;j++){
			if(tong[a[j]]!=0){
				while(st[tot]!=a[j]){
					tong[st[tot]]=0;
					tot--;
				}
			}else{
				st[++tot]=a[j];
				tong[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(tong[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}