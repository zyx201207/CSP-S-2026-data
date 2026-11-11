#include<bits/stdc++.h>
#define UNDERLINE
using namespace std;
using ll=long long;
ll a[500010];
ll diff[500010];
ll n,m;
void judge1(){//personalty a&b
	ll DFF=abs(a[2]-a[1]);
	ll ans=0,index=1;
	while(ans+DFF*index<=m)ans+=DFF*index++;
	cout<<min(index,n);
}void judge2(){
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		diff[i]=a[i]-a[i-1];
	}ll mx=0;
	for(int i=1;i<=n;i++){
		ll ans=0,num=0;
		while(ans<m){
			++num;
			ans+=num*diff[i+num];
		}mx=max(num,mx);
		if(mx+i>=n)break;
	}cout<<min(mx+1,n);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n>5000){
		judge1();
	}else judge2();
	return 0;
}