//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int t,n,m,a[2000010],b[2000010],c[2000010],d[2000010],e[2000010],ans;
//signed main(){
//	freopen("migrate3.in","r",stdin);
//////	freopen("migrate.in","r",stdin);
////	freopen("migrate.out","w",stdout);
//	scanf("%lld%lld",&t,&t);
//	for(;t--;){
//		scanf("%lld%lld",&n,&m);
//		for(int i=1;i<=n;i++){
//			scanf("%lld",&a[i]);
//		}
//		b[n]=n;
//		int x=n;
//		for(int i=n-1;i>=1;i--){
//			for(;a[x]-a[i]>m;x--);
//			b[i]=x;
//		}
//		x=1;
//		c[1]=1;
//		for(int i=2;i<=n;i++){
//			for(;a[i]-a[x]>m;x++);
//			c[i]=x;
//		}
//		for(int i=1;i<=n;i++){
//			d[i]++;
////			if(c[b[i]]==i){
//				d[b[i]]+=d[i];
////			}
////			d[i]=1,d[i]+=d[c[i]];
//		}
//		for(int i=n;i>=1;i--){
////			e[i]=1;
////			if(c[b[i]]==i){
////				e[i]+=e[b[i]];
////			}
//			e[i]++;
//			if(b[i-1]!=n){
//				e[i]+=e[b[i]];
//			}
//		}
//		for(int i=1;i<=n;i++){
//			if(b[i]==i+1)continue;
//			int x=b[b[i]-1],y=max(b[i],b[b[i]-2])+1;
//			if(y<=x){
//				ans+=d[i]*e[x];
////				printf("!%lld %lld %lld!\n",i,j,d[i]*e[j]); 
//			}
//		}
////		for(int i=1;i<=n;i++){
////			printf("?%lld %lld %lld %lld?\n",b[i],c[i],d[i],e[i]);
////		}
//		printf("%lld\n",ans);
//		ans=0;
//		for(int i=1;i<=n;i++)a[i]=b[i]=c[i]=d[i]=e[i]=0;
//	}
//}
///*
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
//
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
//
//0 1
//6 4
//-3 0 1 2 3 4
//
//0 1
//7 666666666666666663
//-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
//*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,a[2000010],b[2000010],d[2000010],l,r,ans;
pair<int,int>c[2000010];
signed main(){
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&t,&t);
	for(;t--;){
		bool ok=1;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i!=1&&a[i]-a[i-1]!=a[2]-a[1])ok=0;
//			b[i].clear();
		}
		if(ok){
			int x=m/(a[2]-a[1]);
			x=x*2-1;
			if(x<2){
				printf("0\n");
				continue;
			}
			for(int i=1;i<=n;i++){
				if(i+x-1<n){
					ans++;
				}
			}
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
//		printf("!!!!!");
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>m){
//					if(j-1>i)b[i].push_back(j-1);
//					if(j-2>i)b[i].push_back(j-2);
					break;
				}
//				if(abs(i-j)<=2)
				b[i]=j;
//				printf("%d->%d\n",i,j);
			}
		}
		for(int i=1;i<=n;i++){
			l=r=1,d[1]=i,c[i]={1,1};
			for(;l<=r;){
				int x=d[l];
				l++;
				for(int j=x+1;j<=b[x];j++){
					if(!c[j].first){
						c[j]=c[x],c[j].first++,d[++r]=j;
//						printf("!%d %d!\n",j,x);
					}
					else if(c[x].first+1==c[j].first){
						c[j].second+=c[x].second;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
//				if(n<=10)printf("%d->%d:%d %d",i,j,c[j].first,c[j].second);
				if(c[j].second==2){
					ans++;
//					if(n<=10)printf("!%d %d!",i,j);
//					if(c[j].first==c[j-1].first&&c[j-1].second==2){
//						printf("%d->%d:%d %d\n",i,j-1,c[j-1].first,c[j-1].second);
//						printf("%d->%d:%d %d\n\n",i,j,c[j].first,c[j].second);
//					}
				}
//				if(c[j].second==1){
//					printf("?%d %d?\n",i,j);
//				}
//				if(n<=10)printf("\n");
//				c[j]={0,0};
			}
			for(int j=1;j<=n;j++)c[j]={0,0};
		}
		for(int i=1;i<=n;i++)b[i]=0,c[i]={0,0};
		printf("%lld\n",ans);
		ans=0;
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989


¡£¡£¡£ 
*/
