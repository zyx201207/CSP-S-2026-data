#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],ans[300005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int k=1;k<s;k++){
				if(b[k]==a[j]){
					s=k;
					flag=1;
					break;
				}
			}
			if(flag==0){
//				cout<<a[j]<<'\n';
				b[s+1]=a[j];
				s++;
			}
		}
		for(int j=1;j<=s;j++){
//			cout<<b[j]<<" ";
			if(vis[b[j]]==0){
				ans[b[j]]++;
				vis[b[j]]=1;
			}
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

