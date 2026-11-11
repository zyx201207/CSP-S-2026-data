#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5,M=1e7+5;
int n;
int a[N];
ll m;
char c[N];
char S[M];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cin>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)S[++m]=c[i];
	}
	for(int i=1;i<=m/2;i++){
		if(S[i]!=S[m-i+1])ans++;
	}
	/*
	int i=1,j=n;
	ll l=1,r=m;
//	cout<<l<<" "<<r<<"\n"; 
	while(l<=m/2&&i!=j){
	//	cout<<r<<" "<<f[j]<<":";
		ll x=s[i]-l,y=r-s[j-1],z=min(x,y);
		if(l+z>=m/2)z=m/2-l+1;
		if(c[i]!=c[j])ans+=z;
		l+=z;
		r-=z;
		if(x<y)i++;
		if(x>y)j--;
		if(x==y)i++,j--;
	//	cout<<x<<" "<<y<<" :";
	//	cout<<l<<" "<<r<<" "<<i<<" "<<j<<":"<<ans<<"\n";
	//	cout<<(l+r)/2<<" "<<m/2<<"\n";
	}*/
	printf("%lld",ans);
	return 0;
}
