#include<bits/stdc++.h>
using namespace std;
const int MAXN=5E5+5;
int n;
long long m,t;
long long a[MAXN];
long long ans;
bool check(){
	for(int i=1;i<=n;++i)if(a[i]!=i)return false;
	return true;
}
bool check1(){
	for(int i=3;i<=n;++i)if(a[i]-a[i-1]!=a[i-1]-a[i-2])return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(check()){
		int i;
		for(i=1;i*(i+1)/2<=m;++i);
		cout<<i<<endl;
		return 0;
	}
	if(check1()){
		int i;
		for(i=1;i*(i+1)/2*(a[2]-a[1])<=m;++i);
		cout<<i<<endl;
	}
	sort(a+1,a+1+n);
	long long ma=a[n];//×î´óÖµ 
	for(int i=1;i<=n;++i)t+=ma-a[i];
	if(t<m){
		cout<<n<<endl;
		return 0;
	}
//	for(int i=1;i<=n;++i)cout<<a[i]<<' ';
//	cout<<endl;
	for(long long r=1;r<=n;++r){
		long long l=r;
		long long t=m;
		while(t>=0&&l>=1){
			t-=(a[r]-a[l--]);
		}
		if(l==0)l++;
		if(t<0)l+=2;
//		cout<<l<<' '<<r<<endl;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
