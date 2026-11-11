#include<bits/stdc++.h>
using namespace std;
long long typedef ll;
ll n,m,a[100005],b[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<1;
	}else if(n==2){
		if(a[2]-a[1]<=m)cout<<2;
		else cout<<1;
	}else if(n==3){
		if(a[3]-a[2]+a[3]-a[1]<=m)cout<<3;
		else if(a[2]-a[1]<=m||a[3]-a[2]<=m)cout<<2;
		else cout<<1;
	}else if(n==4){
		if(a[4]-a[3]+a[4]-a[2]+a[4]-a[1]<=m)cout<<4;
		else if(a[3]-a[2]+a[3]-a[1]<=m||a[4]-a[3]+a[4]-a[2]<=m)cout<<3;
		else if(a[2]-a[1]<=m||a[3]-a[2]<=m||a[4]-a[3]<=m)cout<<2;
		else cout<<1;
	}else if(n==5){
		if(a[5]*4-a[4]-a[3]-a[2]-a[1]<=m)cout<<5;
		else if(a[4]*3-a[3]-a[2]-a[1]<=m||a[5]*3-a[4]-a[3]-a[2]<=m)cout<<4;
		else if(a[3]*2-a[2]-a[1]<=m||a[4]*2-a[3]-a[2]<=m||a[5]*2-a[4]-a[3])cout<<3;
		else if(a[2]-a[1]<=m||a[3]-a[2]<=m||a[4]-a[3]<=m||a[5]-a[4]<=m)cout<<2;
		else cout<<1;
	}else{
		for(int i=1;i<=n;i++){
			b[i]+=b[i-1]; 
		}
		if(a[n]*(n-1)-b[n-1]<=m)cout<<n;
		else if(a[n-1]*(n-2)-b[n-2]<=m)cout<<n-1;
		else if(a[n-2]*(n-3)-b[n-3]<=m)cout<<n-2;
		else if(a[n-3]*(n-4)-b[n-4]<=m)cout<<n-3;
		else if(a[n-4]*(n-5)-b[n-5]<=m)cout<<n-4;
		else if(a[n-5]*(n-6)-b[n-6]<=m)cout<<n-5;
		else if(a[n-6]*(n-7)-b[n-7]<=m)cout<<n-6;
		else if(a[n-7]*(n-8)-b[n-8]<=m)cout<<n-7;
		else if(a[n-8]*(n-9)-b[n-9]<=m)cout<<n-8;
		else if(a[n-9]*(n-10)-b[n-10]<=m)cout<<n-9;
		else if(a[n-10]*(n-11)-b[n-11]<=m)cout<<n-10;
		else if(a[n-11]*(n-12)-b[n-12]<=m)cout<<n-11;
		else if(a[n-12]*(n-13)-b[n-13]<=m)cout<<n-12;
		else if(a[n-13]*(n-14)-b[n-14]<=m)cout<<n-13;
		else if(a[n-14]*(n-15)-b[n-15]<=m)cout<<n-14;
		else if(a[n-15]*(n-16)-b[n-16]<=m)cout<<n-15;
		else if(a[n-16]*(n-17)-b[n-17]<=m)cout<<n-16;
		else if(a[n-17]*(n-18)-b[n-18]<=m)cout<<n-17;
		else if(a[n-18]*(n-19)-b[n-19]<=m)cout<<n-18;
		else if(a[n-19]*(n-20)-b[n-20]<=m)cout<<n-19;
		else if(a[n-20]*(n-21)-b[n-21]<=m)cout<<n-20;
		else if(a[n-21]*(n-22)-b[n-22]<=m)cout<<n-21;
		else if(a[n-22]*(n-23)-b[n-23]<=m)cout<<n-22;
	}
	return 0;
} 
