#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500001],b[300001],c[300001];
deque<ll>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		q.clear();
		fill(begin(c),end(c),0);
		for(ll j=i+1;j<=n;j++){
			if(!c[a[j]]){
				q.push_back(a[j]);
				c[a[j]]=q.size();
			}
			else{
				for(ll ij=1;ij<=q.size()-c[a[j]]+2;ij++){
					q.pop_back();
				}
				q.push_back(a[j]);
				c[a[j]]=q.size();
			}
		}
		for(auto it:q){
			b[it]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
