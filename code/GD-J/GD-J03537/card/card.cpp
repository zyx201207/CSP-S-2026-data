#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,m,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		vector<ll> d(0);
		for(int j=i;j<=n;++j){
			ll f=-1;
	        for(int h=0;h<d.size();++h){
	        	if(d[h]==a[j]){
	        		f=h;
				}
			}
			if(f>=0)d.erase(d.begin()+f,d.end());
			d.push_back(a[j]);
		}
		for(auto i:d){
		   b[i]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<b[i]<<" ";
	}
	return 0;
}
/*
4 3 
1 2 1 3
*/
