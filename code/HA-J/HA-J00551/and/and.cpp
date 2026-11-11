#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll e[35]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
ll max(ll a,ll b){
	if(a>b){
		return a;
	}if(a<b){
		return b;
	}if(a==b){
		return a;
	}
}
string zh(ll x){
	string s;
	ll x1=x;
	for(ll i=30;i>=1;i--){
		if((ll)(x1-e[i])>=0){
			x1=x1-e[i];
			s+='1';
		}else{
			s+='0';
		}
	}
	return s;
}
string andd(ll x,ll y){
	string xx=zh(x),yy=zh(y);
	string s;
	for(int i=0;i<30;i++){
		s+=((xx[i]-'0') and (yy[i]-'0'))+'0';
	}
	return s;
}
ll zh1(string s){
	ll sum=0;
	for(int i=0;i<30;i++){
		sum+=e[30-i]*(s[i]-'0');
	}
	return sum;
}
ll a[200005];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll ans=-9999;
	ll ans1=999;
	ll maxxx=-999;
	ll maxq=-999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
	}
	if(m==1){
		cout<<maxxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxq=max(maxq,zh1(andd(a[i],a[j])));
				}
			}
		}
		cout<<maxq;
		return 0;
	}
	if(m==n){
		ll ansqw=a[1];
		for(int i=2;i<=n;i++){
			ansqw=zh1(andd(ansqw,a[i]));
		}
		cout<<ansqw;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ll anss=a[1];
	for(int i=2;i<=m;i++){
		string qwqq=andd(anss,a[i]);
		anss=zh1(qwqq);
	}
	cout<<anss;

	return 0;
}

