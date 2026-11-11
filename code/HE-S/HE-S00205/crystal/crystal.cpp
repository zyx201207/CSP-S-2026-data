#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int MAXN=5e5+105;
int a[MAXN];
struct fl{
	int num=0;
	int id=0;
}dp[1000086];
int check(int k){//kÎª±àºÅ 
	int sum=0;
	for(int i=1;i<=k;i++)sum+=(a[k]-a[i]);
	return sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
/*	int z=1;
	int last=a[z];
	int laz=1;
	a[0]=0;
	while(z<=n){
		laz=z;
		while(last==a[z])z++;
		for(int i=laz;i<=z;i++){
			dp[i]=dp[]
		}
	}
	int l=1,r=n;
	if(check(n)<=m){
		cout<<n<<endl;
		return 0;
	}*/
	if(n>5000){
			int l=1,r=n;
	if(check(n)<=m){
		cout<<n<<endl;
		return 0;}
	while(l<r){
		int mid=(l+r+1)/2;
		int now=check(mid); 
		if(now>m)r=mid-1;
		else if(now<m)l=mid;
		else {
			l=mid;
			break;
		}
	}
	while(a[l+1]==a[l])l++;
	cout<<l<<endl;
	return 0;}
	else {
		int maxx=0;
		for(int i=1;i<=n;i++){
			int lm=m;
			int sc=i-1;
			while(lm>=0&&sc>=1){
			if(a[i]-a[sc]<=lm)lm-=(a[i]-a[sc]),sc--;
			else break;}
			maxx=max(maxx,i-sc);
		}
		cout<<maxx<<endl;
		return 0;
	}
} 
