#include<bits/stdc++.h>
using namespace std;
namespace MYQ{
	const int N=2000006;
	int t,n,si[N],sj[N],L[N],R[N];
	long long m,a[N],ans;
	char buf[100005],*p1=buf,*p2=buf;
	inline char gc(){
		return (p1==p2&&(p2=(p1=buf)+fread(buf,1,100005,stdin),p1==p2))?EOF:*p1++;
	}
	inline long long read(){
		long long x=0;
		int ff=0;
		char y=gc();
		while(y<'0'||y>'9')
			ff|=(y=='-'),y=gc();
		while('0'<=y&&y<='9'){
			x=(x<<3)+(x<<1)+(y^48);
			y=gc();
		}
		return ff?-x:x;
	}
	int main(){
		read(),t=read();
		while(t--){
			n=read(),m=read();
			for(int i=1;i<=n;i++)
				a[i]=read();
			for(int i=1,j=1;i<=n;i++){
				while(a[i]-a[j]>m)
					j++;
				L[i]=j;
			}
			for(int i=n,j=n;i>0;i--){
				while(a[j]-a[i]>m)
					j--;
				R[i]=j;
			}
			ans=0;
			for(int i=1;i<=n;i++)
				si[i]=0,sj[i]=0;
			for(int i=1;i<=n;i++){
				si[i]++;
				if(R[i]>i+1){
					if(L[R[i]-1]==i)
						sj[R[i]]+=si[i];
					else
						sj[R[i]]++;
				}
				if(L[R[i]]==i)
					si[R[i]]+=si[i];
				else
					si[R[i]]++;
			}
			for(int i=1;i<=n;i++)
				si[i]=0;
			for(int i=n;i>0;i--){
				si[i]++;
				if(L[i]<i-1){
					if(R[L[i]+1]==i)
						ans+=1ll*si[i]*sj[L[i]+1];
					else
						ans+=sj[L[i]+1]; 
				}
				if(R[L[i]]==i)
					si[L[i]]+=si[i];
				else
					si[L[i]]++;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	MYQ::main();
	return 0;
}
