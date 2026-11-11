#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,m,a[N],f[N],mm,ans;
ll ze(ll x){
	ll j=-1,z=0;
	string d;
	while(x>0){
		j++;
		d[j]=(x%2+'0');
		x/=2;
	}
	while(j>=0){
		z=z*10+(d[j]-'0');
		j--;
	}
	return z;
}
ll awy(ll x,ll y){
	string s;
	ll j=-1,z=0;
	x=ze(x);
	y=ze(y);
	while(x>0 and y>0){
		j++;
		if(x%10==1 and y%10==1){
			s[j]='1';
		}else{
			s[j]='0';
		}
		x/=10;
		y/=10;
	}
	while(j>=0){
		z=z*2+(s[j]-'0');
		j--;
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	mm=a[1];
	ans=a[2];
	for(int i=2;i<=n;i++)mm=awy(mm,a[i]);
	for(int i=3;i<=n;i++)ans=awy(ans,a[i]);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(m==n){
		cout<<mm;
		return 0;
	}else if(m==2){
		cout<<awy(a[n],a[n-1]);
		return 0;
	}else if(m==n-1){
		cout<<ans;
		return 0;
	}
	return 0;
}