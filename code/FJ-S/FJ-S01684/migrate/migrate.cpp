#include<bits/stdc++.h>
using namespace std;

long long n,d,a[2000005];
long long li[2000005];

long long f(long long x){
	long long l=1,r=n;
	while(l<r){
		long long mid=l+((r-l+1)>>1);
		if(a[mid]<=x) l=mid;
		else r=mid-1; 
	}
	return l;
}

long long sum,ji=0;
void dfs(long long l,long long r,long long shu){
	if(l==r){
		if(shu>ji){
			return ;
		}
		if(shu==ji){
			++sum;
			return ;
		}
		if(shu<ji){
			ji=shu;
			sum=1;
			return ;
		}
	}
	for(int i=l+1;i<=li[l]&&i<=r;++i){
		dfs(i,r,shu+1);
	}
}

//long long z(long long i,long long j){
//	return i*(n-1)+j;
//}

//long long dp1[2000005];
//void dfs2(long long id,long long l,long long r,long long ci){
//	if(l>=r) return ;
//	cout<<l<<" "<<r<<" "<<ci<<"\n";
//	for(int i=l;i<=r;++i) dp1[z(id,i)]=ci+1;
//	if(r==n) return ;
//	dfs2(id,r+1,min(n,li[r]),ci+1);
//}

long long read(){
	long long xx=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&'9'>=c){
		xx=(xx*10)+(long long)(c-'0');
		c=getchar();
	}
	return f*xx;
}

//long long dp[2000005];
	
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long t=0;
	t=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i)
			li[i]=f(a[i]+d);
			
		//memset(dp1,0x3f,sizeof(dp1));
		//for(int i=1;i<=n;++i) dfs2(i,i,li[i],0);
		//for(int i=1;i<=n;++i){
		//	for(int j=1;j<=n;++j){
		//		if(dp1[z(i,j)]>=100)
		//			cout<<"- ";
		//		else
		//			cout<<dp1[z(i,j)]<<" ";
		//	}
		//	cout<<"\n";
		//}
		
		long long ans=0;
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j){
				sum=0,ji=INT_MAX;dfs(i,j,0);
				if(sum==2) ++ans;
			}
		cout<<ans<<"\n";
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
