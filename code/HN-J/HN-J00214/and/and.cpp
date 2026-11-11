#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,pd,cnt,q;
signed main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	cnt=n,q=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	for(int i=30;i>=0;i--){
		pd=(1<<i);
		int jl=0,qs=0,zd;
		for(int j=q;j<=cnt;j++){
			if(a[j]>=pd){
				a[j]-=pd;
				jl++;
				zd=j;
				if(a[j+1]<pd) break;
			}
			else if(a[j+1]>=pd) qs=j;
		}
		if(jl>=m) ans+=pd,cnt=zd,q=qs;
	}
	cout<<ans;
	return 0;
} 
