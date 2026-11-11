#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define _  200005
#define __ 2003
using namespace std;
int n,m;
ll f[__][__],a[_],ans;
bool A=true;
int main(){
	freopen("and.in" ,"r",stdin );
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n)
		scanf("%lld",&a[i]);
	rep(i,1,n)
		if(!((1ll<<((ll)(log2(a[i]+1)*1ll)))-1==a[i]))
			A=false;
	if(m==1){
		rep(i,1,n)
			ans=max(ans,a[i]);
	}
	else if(m==n){
		ans=INT_MAX;
		rep(i,1,n)
			ans=ans&a[i];
	}
	else if(m==2){
		rep(i,1,n)
			rep(j,i+1,n)
				ans=max(ans,a[i]&a[j]);
	}
	else if(A){
		sort(a+1,a+n+1);
		ans=INT_MAX; 
		rep(i,n-m+1,n)
			ans&=a[i];
	}
	else{
		rep(j,0,m)
			f[0][j]=INT_MAX;
		rep(i,0,n)
			f[i][0]=INT_MAX;
		rep(i,1,n){
			f[i][1]=max(f[i-1][1],a[i]);
			f[i][i]=f[i-1][i]&a[i];
		}
		rep(i,1,n)
			rep(j,1,min(i,m))
				f[i][j]=max(f[i-1][j]==INT_MAX?0:f[i-1][j],(f[i-1][j-1]&a[i])==INT_MAX?0:(f[i-1][j-1]&a[i]));
	//	rep(i,1,n)
	//		rep(j,1,min(i,m))
	//			cout<<i<<','<<j<<':'<<f[i][j]<<endl;
		ans=f[n][m];
	}
	printf("%lld",ans);
	return 0;
} 
/*

4 2
3 15 12 12

5 3
31 3 1 15 7

*/
