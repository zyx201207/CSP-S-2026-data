#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],b[N],ans[N];
stack<ll> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=n;i>=1;i--){
		s.push(a[i]);
		b[a[i]]++;
		if(b[a[i]]==2){
			s.pop(),b[a[i]]--;
			while(s.top()!=a[i]) b[s.top()]--,s.pop();
		}
		stack<ll> s1=s;
		while(s1.size()) ans[s1.top()]++,s1.pop();
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

