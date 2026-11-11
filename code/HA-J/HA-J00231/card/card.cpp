#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans[300005],a[500005],temp[500005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp[j]=0;
			vis[j]=0;
		}
		ll cnt=0;
		for(int j=i;j<=n;j++){
			ll id=0;
			for(int k=1;k<=cnt;k++){
				if(temp[k]==a[j]){
					id=k;
					break;
				}
			}
			if(id!=0){
				cnt=id-1;
			}
			temp[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			vis[temp[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
