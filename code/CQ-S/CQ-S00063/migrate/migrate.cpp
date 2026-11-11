#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=2e6+10;
inline int readInt(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline ll readll(){
	char c=getchar();ll x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1ll;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10ll+c-'0';c=getchar();}
	return x*f;
}
int c,t,n,s,lt,l,r,mid,x,i,se;
ll d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=readInt(),t=readInt();
	while(t--){
		n=readInt(),d=readll(),s=0,lt=1;
		for(i=1;i<=n;i++) a[i]=readll();
		i=4;
		while(i<=n){
			if(i-lt>=3){
				if(i-lt==3){
					if(a[i]-a[i-3]>d){
						if(a[i-2]-a[i-3]<=d&&a[i]-a[i-2]<=d
						&&a[i-1]-a[i-3]<=d&&a[i]-a[i-1]<=d){
							l=lt,r=i;
							while(a[r]+d>=a[r+1]&&a[r-1]+d<a[r+1]&&r<=n){s++,r++;}
							while(a[l-1]+d>=a[l]&&a[l-1]+d<a[l+1]&&l>=1){s++,l--;}
							if(r>n) break;
							s++,lt++,i++;
						}else lt++;
					}else i++;
				}
				else{
					if(a[i]-a[lt]<=d){
						i++;
						continue;
					}
					l=lt,r=i,se=0;
					while(l<=r){
						mid=(l+r)/2;
						if(a[mid]>=a[i]-d) r=mid-1,x=mid;
						else l=mid+1;
					}
					if(a[x-1]-a[lt]<=d&&a[i]-a[x-1]<=d){
						lt++;
						continue;
					}
					for(int j=x;j<=i;j++) if(a[j]-a[lt]<=d) se++;
					if(se==2){
						while(a[r]+d>=a[r+1]&&a[r-1]+d<a[r+1]&&r<=n){s++,r++;}
						while(a[l-1]+d>=a[l]&&a[l-1]+d<a[l+1]&&l>=1){s++,l--;}
						if(r>n) break;
						s++,lt++;
					}else{
						i++;
						continue;
					}
				}
			}else i++;
		}
		printf("%d\n",s);
	}
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4
*/
