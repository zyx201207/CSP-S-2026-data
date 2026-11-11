#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll a[N];
ll ans[N];
ll k[N];
bool check[N];
vector<int>arr;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof(ans));
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		memset(check,false,sizeof(check));
		memset(k,0,sizeof(k));
		for(ll j=i;j<=n;j++){
			if(check[a[j]]==false){
				arr.push_back(a[j]);
				check[a[j]]=true;
				k[a[j]]=j;
			}else{
				ll g=1;
				while(g<=j-k[a[j]]){
					ll cnt=arr.size()-1;
					check[arr[cnt]]=false;
					k[arr[cnt]]=j;
					arr.pop_back();
					g++;
				}
				arr.push_back(a[j]);
				check[a[j]]=true;
			}
		}
		while(!arr.empty()){
			ll cnt=arr.size()-1;
			ans[arr[cnt]]++;
			arr.pop_back();
		}
		
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
