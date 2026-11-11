#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ma,sum,cnt;
ll a[500005];
deque<ll>q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(ll i=1;i<=n;i++){
		ll dt=a[i]-a[i-1];
		q.push_back(i);
		sum+=dt*q.size()-dt;
		cnt++;
		while(!q.empty()){
			if(sum>m){
				ll tmp=q.front();
				q.pop_front();
				
				sum-=a[i]-a[tmp];
				cnt--;
			}else{
				break;
			}
		}
		
		ma=max(ma,cnt);
	}
	
	cout<<ma;
	
	return 0;
}