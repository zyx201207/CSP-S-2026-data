#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxans=1,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll a[n];
	if(n<=5500&&m<=1e9+10){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		ll cost[n],pos=0;
		cost[0]=0;
		for(ll i=1;i<n;i++){
			cost[i]=(a[i]-a[i-1])*(i-pos)+cost[i-1];
			if(cost[i]>m){
				maxans=max(maxans,i-pos);
				cost[i]=cost[i]-(a[i]-a[pos]);
				pos++;
			}
			ans=i-pos+1;
		}
		maxans=max(maxans,ans);
		cout<<maxans;
	}else{
		ll diff[n];
		int f_1=0,f_2=0;
		cin>>a[0];
		if(a[0]!=1){
			f_2==1;
		}
		for(ll i=1;i<n;i++){
			cin>>a[i];
			diff[i]=a[i]-a[i-1];
			diff[0]=diff[1];
			if(diff[i]!=diff[i-1]){
				f_1=1;
			}
			if(a[i]!=i+1){
				f_2=1;
			}
		}
		if(f_2==0){
			ll b=1;
			for(int i=1;;i++){
				b*=i;
				if(b>m){
					cout<<i;
					return 0;
				}
			}
		}
		if(f_1==0){
			ll b=diff[1]-diff[0];
			for(int i=1;;i++){
				b+=i*(diff[1]-diff[0]);
				if(b>m){
					cout<<i;
					return 0;
				}
			}
		}
		cout<<sqrt(n);
	}
	
	return 0;
}
