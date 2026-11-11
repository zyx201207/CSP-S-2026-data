#include<bits/stdc++.h>
#define x0 x_0
#define x1 x_1
#define y0 y_0
#define y1 y_1
#define yn y_n
#define j0 j_0
#define j1 j_1
#define jn j_n
#define k0 k_0
#define k1 k_1
#define d0 d_0
#define d1 d_1
#define LL long long
#define LD long double
#define Big __int128
#define STR string
#define US unsigned
#define ZPB push_back
#define ZPF push_front
#define PPB pop_back
#define PPF pop_front
#define next NXTNXT
#define UPB upper_bound
#define LWB lower_bound
#define mem(x,val) memset(x,val,sizeof(x))
using namespace std;
const int N=2000010,INTmex=(int)1e9+2;
int c,test,n,jmpl[N],jmpr[N],lft[N],rgt[N],fasl[N],fasr[N];
LL d,x[N],ans;
void Init(){
	for(int i=0;i<=n+1;++i) lft[i]=rgt[i]=fasl[i]=fasr[i]=0;
	ans=0;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>test;
	while(test--){
		Init(),cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		// query jmpr( -> )
		int zz=1;
		for(int i=1;i<=n;++i){
			while(zz<n && x[zz+1]-x[i]<=d) ++zz;
			jmpr[i]=zz;
		}
		// query jmpl( <- )
		zz=1;
		for(int i=1;i<=n;++i){
			while(zz<n && x[i]-x[zz]>d) ++zz;
			jmpl[i]=zz;
		}
		// query lft
		for(int i=1;i<=n;++i){
			++lft[i]; // it can be the first-point
			if(i==n) continue;
			// lft[i] -> lft[j]: i < j
			int j=jmpr[i];
			// if j is start-point: [j, i] is the maximum - length
			if(i==1 || x[j]-x[i-1]>d) fasl[j]+=lft[i]-1;
			++fasl[j];
			// if j not start-point: |x[j] - x[i-1]| > d (can't remove front) and [i, j] is the maximum - length
			if(i==1 || x[j]-x[i-1]>d) lft[j]+=lft[i]-1;
			++lft[j];
		}
		// query rgt
		for(int i=n;i>=1;--i){
			++rgt[i]; // it can be the last-point
			if(i==1) continue;
			// rgt[i] -> rgt[j]: i > j
			int j=jmpl[i];
			// if j is end-point: |x[i] - x[j-1]| > d (can't remove front)
			if(i==n || x[i+1]-x[j]>d) fasr[j]+=rgt[i]-1;
			++fasr[j];
			// if j not end-point: |x[i] - x[j-1]| > d (can't remove front) and [j, i] is the maximum - length
			if((i==n || x[i+1]-x[j]>d) && x[i]-x[j-1]>d){
				rgt[j]+=rgt[i]-1;
			}
			++rgt[j];
		}
		for(int i=1;i<=n-2;++i){
			// find (i,j,k)
			if(x[i+1]-x[i]>d) continue;
			int j=jmpr[i];
			if(j-i==1) continue;
			if(j==n || x[j+1]-x[j]>d) continue;
			int k=jmpr[j];
			// i is start, k is finish
			// we need: i ~ j is maximum - length; x[k] - x[j-1] <= d (=> k <= jmpr[j-1]), and x[k] - x[j-2] > d.
			int L=j+1,R=jmpr[j-1],res=-1;
			while(L<=R){
				int mid=(L+R)>>1;
				if(x[mid]-x[j-2]>d) res=mid,R=mid-1;
				else L=mid+1;
			}
			if(~res) ans+=jmpr[j-1]-res+1;
			// i is start, k isn't finish
			if(x[k]-x[j-1]<=d && x[k]-x[j-2]>d){
				// j ~~~~ k is maximum - length (is true), so we can't "if" is.
				ans+=fasr[k];
			}
			// i isn't start, k is finish
			if(i>1 && x[j-1]-x[i-1]>d && (~res)){
				ans+=(LL)fasl[i]*(jmpr[j-1]-res+1);
			}
			// i isn't start, k isn't finish
			if(x[k]-x[j-1]<=d && x[k]-x[j-2]>d && i>1 && x[j-1]-x[i-1]>d) ans+=(LL)fasl[i]*fasr[k];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
input1:

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

output1:

1
2

input2:

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

output2:

0
1

input3:

0 1
8 19
0 9 12 16 31 38 40 52 

output3:

9

input4:

0 1
8 22
0 2 15 22 34 52 63 69 

output4:

8


*/
