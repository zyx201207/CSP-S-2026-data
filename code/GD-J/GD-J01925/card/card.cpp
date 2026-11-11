#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,m,v[1000005],vis[10000005],a[10000004];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   cin>>n>>m;
   for(ll i=1;i<=n;i++){
   	cin>>v[i];
   }
   for(ll i=1;i<=n;i++){
   	for(ll j=i;j<=n;j++){
		if(vis[v[j]]==0){
			vis[v[j]]=1;
		}else{
			for(ll k=1;k<=m;k++){
				vis[k]=0;
			}
			vis[v[j]]=1;
		}
	}
	for(ll j=1;j<=m;j++){
		if(vis[j]==1)a[i]++;
		
		cout<<vis[j]<<" ";
		}
		
		cout<<endl;
   }
   for(ll i=1;i<=m;i++){
   cout<<a[i]<<" ";
   }
    return 0;
}
