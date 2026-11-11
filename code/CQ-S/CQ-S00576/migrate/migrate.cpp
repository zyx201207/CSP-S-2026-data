#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
		int r=4;
		long long ans=0;
		for(int i=1;i+3<=n;++i){
			if(x[i+1]-x[i]>d||x[i+2]-x[i+1]>d||x[i+2]-x[i]>d||x[i+3]-x[i+1]>d)continue;
//			printf("%d\n",x[i+3]-x[i]); 
			int l=i-1,cl=1,cr=1;
			while(l-1>=0&&x[i+1]-x[l]<=d)l--;
			
			while(l-1>=1&&x[i]-x[l]<=d){
				l--;
				cl++;
			}
			r=max(r,i+3);
			while(r+1<=n+1&&x[r+1]-x[i+2]<=d)r++;
			while(r+1<=n&&x[r+1]-x[i+3]<=d){
				r++;
				cr++;
			}
			ans+=cl*cr;
//			printf("%d %d %d %d %d\n",i,l,r,cl,cr);
		}
		printf("%lld\n",ans);
	}
    return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

0 1
10 3
0 3 6 7 8 9 10 11 14 17

*/
