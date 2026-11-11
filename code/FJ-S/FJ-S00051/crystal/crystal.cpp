#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int N=5e5+5;

int n,ans,now_it;
ll m,last;
ll a[N];
queue<ll> q;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)	 cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		m-=(a[i]-last)*now_it;
		while(m<0){
			int x=q.front();	q.pop();
			m+=a[i]-x,now_it--;
		}
		now_it++,last=a[i],q.emplace(a[i]);
		ans=max(ans,now_it); 
	}
	cout<<ans;
	
	return 0;
} 
