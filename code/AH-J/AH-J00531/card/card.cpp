#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		set<ll>f;
		stack<ll>s;
		for(ll j=i;j<=n;i++){
			while(f.count(a[j]))f.erase(f.find(s.top())),s.pop();
			s.push(a[j]);
			f.insert(a[j]);
		}for(auto it=f.begin();it!=f.end();it++)
			ans[*it]++;
	}for(ll i=1;i<=m;i++)
		cout<<ans[i];
	return 0;
}
