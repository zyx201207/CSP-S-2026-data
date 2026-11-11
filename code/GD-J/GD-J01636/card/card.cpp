#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
ll n,m,a[maxn],ans[maxn];
vector<ll>b[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].push_back(i);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(b[a[j]][b[a[j]].size()-1]>=i){
				ans[a[j]]++;
				j=b[a[j]][b[a[j]].size()-1];
			}
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
