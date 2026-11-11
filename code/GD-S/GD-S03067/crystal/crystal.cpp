#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],n,m,d[500005],mx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll t=0;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
		//cout<<d[i]<<' ';
		ll l=(d[i]-d[t])/(i-t),r=(d[i]-d[t]+m)/(i-t);
	//cout<<a[i]<<' '<<l<<' '<<r<<endl;
		if(a[i]>=l&&a[i]<=r) mx=max(mx,i-t);
		else{
			while(t<i){
				t++;
				l=(d[i]-d[t])/(i-t),r=(d[i]-d[t]+m)/(i-t);
	//cout<<a[i]<<' '<<l<<' '<<r<<endl;
				if(a[i]>=l&&a[i]<=r){
					break;
				}
			}
		}
	}
	cout<<mx;
	return 0; 
}
