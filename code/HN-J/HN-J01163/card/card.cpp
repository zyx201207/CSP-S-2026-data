#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,k,m;
	cin>>n>>m;
	vector<ll> a(n+2,0);
	int bj[300010]={};
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<n;i++){
		vector<ll> b,d,d1;
		for(int j=i;j<n;j++)b.push_back(a[j]);
		int sz=b.size();
		for(int j=0;j<sz;j++){
			vector<ll> d1; 
			for(int k=0;k<d.size();k++){
				if(d[k]==b[j]){
					break;
				}
				d1.push_back(d[k]);
			}
			d.clear();
			for(int k=0;k<d1.size();k++){
				d.push_back(d1[k]);
			}
			d.push_back(b[j]);
		}
		for(int k=0;k<d.size();k++)bj[d[k]]++;
	}
	for(int i=1;i<=m;i++)cout<<bj[i]<<' ';
	return 0;
}
