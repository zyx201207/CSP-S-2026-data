#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e6+5;
//const int inf=1e9;
//long long las[N*2],nex[N*2],cnt=0,h[N];
//void add(long long x,long long y){
//	las[++cnt]=y;
//	nex[cnt]=h[x];
//	h[x]=cnt;
//}
long long a[N],b[N],c[N],n,k,tt,ttt,o=0;
long long f[N],g[N],sum[N];
long long s[N];//子树大小
long long d[N];//计算这里作为1的起点的个数
long long ss[N],aa[N],bb[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("a.txt","r",stdin);
//	freopen("c.txt","w",stdout);
	scanf("%lld%lld",&ttt,&tt);
	while(tt--){
		o++;
		scanf("%lld%lld",&n,&k);
//		bool ff=false;
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
//			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
////				cerr<<i<<"!!!"<<endl;
//				ff=true;
//			}
		}
//		bool gg=false;
		for(long long i=1;i<=n;i++){
			b[i]=upper_bound(a+1,a+1+n,a[i]+k)-a-1;
//			if(i+2<=n&&i+2!=b[i]){
//				ff=true;
//			}
//			if(i+1<=n&&i+1!=b[i]){
//				gg=true;
//			}
			c[i]=lower_bound(a+1,a+1+n,a[i]-k)-a;
		}
		if(ttt<=10){
			long long ans=0;
			for(long long i=1;i<=n;i++){
				f[i]=0;
				g[i]=1;
				sum[i-1]=0;
				sum[i]=1;
				long long x=i;
				long long u=0;
	//			cerr<<i<<":";
				while(1){
					u++;
					if(sum[x]-sum[x-1]>=3){
						break;
					}
					for(long long j=x+1;j<=b[x];j++){
						f[j]=u;
						g[j]=sum[x]-sum[c[j]-1];
	//					cerr<<j<<":"<<f[j]<<" "<<g[j]<<endl;
						if(g[j]==2){
	//						cerr<<i<<" "<<j<<endl;
							ans++;
						}
						sum[j]=sum[j-1]+g[j];
					}
	//				cerr<<x<<" ";
					if(x==b[x]){
						break;
					}
					x=b[x];
				}
	//			cerr<<endl;
	//			cerr<<i<<":";
	//			for(long long j=i+1;j<=n;j++){
	//				f[j]=
	//				f[j]=inf;
	//				g[j]=0;
	//				for(long long k=i;k<j;k++){
	//					if(a[j]-a[k]<=p){
	//						f[j]=min(f[j],f[k]+1);
	//					}
	//				}
	//				for(long long k=i;k<j;k++){
	//					if(a[j]-a[k]<=p){
	//						if(f[j]==f[k]+1){
	//							g[j]+=g[k];
	//						}
	//					}
	//				}
	//				cerr<<f[j]<<" ";
	//				if(g[j]==2){
	//					cerr<<i<<" "<<j<<endl;
	//					ans++;
	//				}
	//			}
	//			cerr<<endl;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(ttt<=12){
			if(b[1]<=2){
				printf("0\n");
			}
			else{
				printf("%lld\n",max(0ll,n-2*(b[1]-1)+1));
			}
			continue;
//			cerr<<o<<"!!!"<<endl;
//			if(b[1]==3){
//				printf("%lld\n",max(0ll,n-3));
//				continue;
//			}
//			if(1){
//				printf("0\n");
//				continue;
//			}
		}
		for(long long i=1;i<=n;i++){
			sum[i]=s[i]=d[i]=ss[i]=0;
			aa[i]=-a[i];
		}
//		if(o!=2){
//			continue;
//		}
		for(long long i=1,j=n;i<j;i++,j--){
			swap(aa[i],aa[j]);
		}
		for(long long i=1;i<=n;i++){
			b[i]=upper_bound(a+1,a+1+n,a[i]+k)-a-1;
			bb[i]=upper_bound(aa+1,aa+1+n,aa[i]+k)-aa-1;
//			cout<<i<<"="<<b[i]<<endl;
//			if(i+2!=b[i]){
//				cerr<<i<<"NO"<<endl;
//			}
//			if(b[i]!=i){
//				add(i,b[i]);
//				add(b[i],i);
//			}
		}
//		cerr<<o<<":"<<b[1]-1<<" "<<n-(b[1]-1)*2+1<<endl;
//		for(long long i=1;i<=n;i++){
//			b[i]=upper_bound(a+1,a+1+n,a[i]+k)-a-1;
//			cerr<<i<<"="<<b[i]<<endl;
////			if(b[i]!=i){
////				add(i,b[i]);
////				add(b[i],i);
////			}
//		}
		for(long long i=1;i<=n;i++){
			s[i]++;
			if(i==b[i]){
				continue;
			}
			if(b[i-1]==b[i]){
				s[i]=1;
			}
//			if(b[i]==b[i-1]){
//				s[b[i]]++;
//			}
//			else{
				s[b[i]]+=s[i];
//			}
		}
		for(long long i=1;i<=n;i++){
			ss[i]++;
			if(i==bb[i]){
				continue;
			}
			if(bb[i-1]==bb[i]){
				ss[i]=1;
			}
//			if(b[i]==b[i-1]){
//				s[b[i]]++;
//			}
//			else{
				ss[bb[i]]+=ss[i];
//			}
		}
		for(long long i=1;i<=n;i++){
			d[i]=ss[n-i+1];
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
//			cerr<<i<<":"<<s[i]<<" "<<d[i]<<endl;
			if(i==b[i]){
				continue;
			}
			if(b[b[i]]==b[b[i]-1]){
				if(b[b[i]-2]==b[b[i]]||b[b[i]]==b[i]){
					continue;
				}
//				if(b[b[b[i]]]!=b[b[b[i]]-1]){
					ans=ans+s[i]*(b[b[i]]-b[b[i]-2]-1+d[b[b[i]]]);
//				}
//				else{
//					ans=ans+s[i]*(b[b[i]]-b[b[i]-2]);
//				}
//				ans=ans+s[i]*(b[b[i]]-b[b[i]-2]-1+d[b[b[i]]]);
//				cerr<<i<<"  +="<<s[i]<<"*"<<(b[b[i]]-b[b[i]-2]-1+d[b[b[i]]])<<endl;
			}
			else{
				if(b[i]==i+1){
					continue;
				}
//				cerr<<i<<"!!!"<<endl;
				ans=ans+s[i]*(b[b[i]-1]-b[b[i]-2]);
//				cerr<<i<<"+="<<s[i]<<"*"<<(b[b[i]-1]-b[b[i]-2])<<endl;
			}
		}
		printf("%lld\n",ans);
//		cout<<ans<<endl;
//		cerr<<ans<<endl;
	}
	return 0;
}
/*

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
8 2
1 2 3 4 5 6 7 8
*/
