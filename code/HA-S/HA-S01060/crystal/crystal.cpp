#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
ll n,m,a[N],ans;
deque<ll>ss;
priority_queue<ll,vector<ll>,greater<ll> >s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	a[n]=INT_MAX;
	ll now=a[0],t=1,cs=-1,cd=-1;
	for(int i=1;i<=n;i++){
		if(now!=a[i]){
			if(t==1){
				cs=now;
			}
			else{
				cd=now;
				ans+=t;
			}
			now=a[i];
			if(cs>=0){
				s.push(now-cs);
			}
			if(cd>=0&&now!=a[i+1]){
				s.push(t*(now-cd));
			}
			t=1;
		}else{
			t++;
		}
	}
	while(!s.empty()&&s.top()<=m){
		ll v=s.top();s.pop();
		m-=v;ans++;
	}
	cout<<ans;
	return 0;
}
