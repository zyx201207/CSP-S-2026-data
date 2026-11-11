#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
ll n,m;
ll sum[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=1;
	ll maxx=0,minn=1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int y=a[1];
		if(a[i]!=y){
			f=0;
		}
		minn=min(a[i],minn);
		maxx=max(a[i],maxx);
	}
	ll b;
	if(f==1){
		cout<<n;
		return 0;
	}
	if(maxx>=m){
		b=maxx;
	}else{
		b=m;
	}
	for(int i=0;i<=b;i++){
		if(a[i]!=a[i-1]){
			sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
		}else{
			sum[i]=sum[i-1];
		}
	}
	for(int i=0;i<=b;i++){
		if(m>=sum[i]&&m<sum[i+1]){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
