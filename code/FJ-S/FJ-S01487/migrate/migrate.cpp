#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;

inline int read(){
	int f=1,x=0;
	char gc=getchar();
	while(gc<'0' || gc>'9'){
		if(gc=='-') f=-1;
		gc=getchar();
	}
	while(gc>='0' && gc<='9'){
		x=x*10+(gc-'0');
		gc=getchar();
	}
	return x*f;
}

int n,d,a[N],l,r,ans;

inline void solve(){
	n=read();d=read();
	ans=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i_l=1,i_r=1,j_l=2,j_r=2;i_l<=n &&j_l<=n;i_l++){
		i_r=i_l;
		j_l=j_r=i_l+1;
		while(a[i_r+2]-a[i_r]>d && a[i_r+1]-a[i_r]<=d) i_r++;
		
		l=r=i_r;
		if(i_r>n) break;
		while(a[j_l]-a[i_r]<=d) j_l++;
		
		if(j_l>n) break;
		while(1){
			while(a[r]-a[i_r]<=d) r++;
			r--;
			j_r=j_l;
			while(a[j_r]-a[r]<=d && j_r<n && a[j_l]+d<=a[j_r]) j_r++;
			if(a[j_r]-d>a[j_l]) j_r--;
			
			while(a[j_l]-a[l]>d && l<=j_l) l++;
			
			
			if(l==j_l) break;
			if(r-l==1){
				ans+=(j_r-j_l+1)*(i_r-i_l+1);
			}
			else if(r-l<=0) break;
			j_l=j_r+1;
			if(j_l>n) break;
		}
	}
	printf("%lld\n",ans);
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--) solve();
	return 0;
}
