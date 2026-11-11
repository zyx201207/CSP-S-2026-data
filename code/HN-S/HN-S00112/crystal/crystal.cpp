#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,INF=2e18;
int n,m,op[N],ch[N],x[N],y[N],maxx=1,pos;
bool ok=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; ++i)cin >>op[i];
	sort(op+1,op+n+1);
	for(int i=2; i<=n; ++i)ch[i-1]=op[i]-op[i-1];
	for(int i=1; i<n; ++i)x[i]=x[i-1]+ch[i]*i;
	for(int i=1; i<n; ++i)y[i]=y[i-1]+ch[i];
	for(int i=2; i<n; ++i){
		if(ch[i]!=ch[i-1])ok=false;
	}
	if(ok){
		int l=1,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(mid*(mid+1)*ch[1]/2<=m)l=mid;
			else r=mid-1;
		}
		printf("%lld",l+1);
		return 0;
	}else{
		for(int i=1; i<n; ++i){
			int sum=0;
			for(int j=i; j<n; ++j){
				sum+=ch[j]*(j-i+1);
				if(sum<=m)maxx=max(maxx,j-i+2);
			}
		}
		printf("%lld",maxx);
	}
//	x[n]=INF;
//	for(int i=1; i<n; ++i){
//		int s=0;
//		if(i>2)s=y[i-2];
//		pos=upper_bound(x+1,x+n+1,m-s+y[n-1]*(i-1))-x;
//		maxx=max(maxx,pos-i+1);
//	}
//	printf("%lld",maxx);
	return 0;
} 
