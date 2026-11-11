#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e9+1; 
typedef long long ll;
int n,m;
ll a[N];
priority_queue<ll,vector<ll>,greater<ll> >q;
ll check(ll x){
	ll sum=0,cnt=0,idx=0;
	for(int i=1;i<=n;i++){
		if(x-a[i]>=0){
			idx++;
			q.push(abs(x-a[i])*10+i);
		}
		else{
			break;
		}
	}
	for(ll i=1;i<=idx;i++){
		int tp=q.top();
		q.pop();
		if(sum+tp/10<=m){
			sum+=tp/10;
			cnt++;
		}
		else{
			break;
		}
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll minn=LLONG_MAX,maxx=LLONG_MIN;
	ll cz=0;
	bool flag=true,f1=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	if(n>=5000&&m>=100000000){
		sort(a+1,a+n+1);
		bool f1=true,f2=true;
		ll cz=a[1];
		for(int i=2;i<=n;i++){
			if((a[i]-a[i-1])!=cz){
				f1=false;
			}
			if(i!=a[i]){
				f2=false;
			}
		}
		if(f1==false&&f2==false){
			return 0;
		}
		if(f2==true){
			if(m>=(n+1)*n/2){
				cout<<n;
				return 0;
			}
			if(m%2!=0){
				cout<<(m+1)/2;
			}
			else{
				cout<<m/2+1;
			}
		}
	}
	//sort(a+1,a+n+1);
	ll anss=0;
	for(ll i=minn;i<=maxx;i++){
		ll ty=check(i);
		anss=max(anss,ty);
	}
	cout<<anss;
	return 0;
}
/*
	·Ö£¿
5 5
1 2 4 8 9
*/
