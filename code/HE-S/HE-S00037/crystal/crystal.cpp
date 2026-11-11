#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,xuan;
ll a[5000100];
priority_queue<ll,vector<ll>,greater<ll> > h;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		ll k1=(a[i]-xuan)*h.size(),k2=(a[i]-xuan)*(h.size()-1);
		if(m<k1){
			if(m+xuan-h.top()>=k2){
				m+=xuan-h.top();
				m-=k2;
				xuan=a[i];
				h.pop();
				h.push(a[i]);
			}
		}
		else{
			h.push(a[i]);
			xuan=a[i];
			m-=k1;
		}
	}
	cout<<h.size();
} /*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
*/
