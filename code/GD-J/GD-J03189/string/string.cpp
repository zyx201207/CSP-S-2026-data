#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=(m);++i)
#define rev(i,n,m) for(int i(n);i>=(m);--i)
#define ll long long
using namespace std;
const int N=2e5+5;
int a[N],b[N];
char ch[N],CH[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m=0,fg=0;
	ll sum=0,ans=0;
	cin>>n;
	rep(i,1,n) cin>>a[i]>>ch[i],sum+=a[i];
	if(sum%2==1) fg=1;
	sum/=2;
	rep(i,1,n){
		if(sum==-1){
			b[++m]=a[i];
			CH[m]=ch[i];
		}
		else if(a[i]>sum){
			b[++m]=sum;
			CH[m]=ch[i];
			b[++m]=a[i]-sum-fg;
			CH[m]=ch[i];
			sum=-1;
		}
		else{
			sum-=a[i];
			b[++m]=a[i];
			CH[m]=ch[i];
		}
	}
	for(int i=1,j=m;i<j;++i){
		while(i<j&&b[j]<b[i]){
			if(CH[i]!=CH[j]) ans+=b[j];
			b[i]-=b[j],--j;
		}
		if(CH[i]!=CH[j]) ans+=b[i];
		b[j]-=b[i];
	}
	cout<<ans;
	return 0;
}
