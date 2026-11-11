#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end(),cmp);
	int mx=0,pos=1,cnt=1;
	__int128 sum=0;
	for(int i=2;i<=n;i++){
		cnt++;
		sum+=(a[i]-a[i-1])*(i-1);
		while(sum>m){
			cnt--;
			sum-=a[i]-a[pos++];
		}
		mx=max(mx,cnt);
	}
	cout<<mx<<'\n';
} 
