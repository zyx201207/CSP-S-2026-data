#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define N 2000010
#define For(i,a,b) for(register int i=a;i<=b;++i)
#define Rof(i,a,b) for(register int i=a;i>=b;--i)
#define ls x<<1
#define rs x<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define pb push_back
#define mk make_pair
#define pque priority_queue

using namespace std;
int R[N];
ll a[N];
ll C,T,n,d,ans;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}  
void sol(){
	n=read(),d=read();
	For(i,1,n) a[i]=read();
	int r=1;
	For(i,1,n){
		while(r<n && a[r+1]-a[i]<=d) r++;
		R[i]=r;
	} 
	ans=0;
	For(i,1,n){
		int v2=0,l2=i,l1=R[i],vis2=0,is=1;
		while(l1<n){
			r=R[l1];
			if(l1==r) break;
			if(vis2){
				ans+=max(0,(r-1)-max(l1,R[l1-1]));
			}else{
				if(l1>l2+2){
					if(v2) ans+=max(0,(r-1)-max(l1,R[l1-1]));
					else ans+=max(0,min(r-1,R[l1-1])-max(l1,R[l1-2]));
				}else if(l1>l2+1){
					if(v2) ans+=max(0,(r-1)-max(l1,R[l1-1]));
					else ans+=max(0,min(r-1,R[l1-1])-l1);
				}else{
					if(v2) ans+=(r-1)-l1;
				}
			}
			/*
			For(j,l1+1,r-1){
				if(!vis2){
					if(l1>l2+1 && a[j]-a[l1-1]<=d){
						if(!v2 && !(l1>l2+2 && a[j]-a[l1-2]<=d)) ans++;
					}else if(v2) ans++;	
				}else{//一定有 v2=1 
					if(!(a[j]-a[l1-1]<=d)) ans++;
				}
			}
			*/
			int now=0;
			if(!vis2){
				if(l1>l2+1 && a[r]-a[l1-1]<=d){
					now=1;
					if(v2) break;
					if(l1>l2+2 && a[r]-a[l1-2]<=d) break;
					v2=1,ans++;
				}else if(v2) ans++;
			}else{//一定有 v2=1 
				if(a[r]-a[l1-1]<=d) break;
				ans++;
			}
			vis2=now,l2=l1,l1=r;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),T=read();
	while(T--) sol(); 
	return 0;
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

*/
