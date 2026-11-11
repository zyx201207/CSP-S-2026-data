#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x){
	bool f=0;
	char ch;
	x=0;
	while(ch=getchar(),(ch<'0'||ch>'9')) if(ch=='-') f=1;
	while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	if(f) x=-x;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar((x%10)+48);
}
int id,T,n,m,a[305],d[305],f[305],s[305],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(id),read(T);
	while(T--){
		read(n),read(m);
		ans=0;
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++){
			d[i]=0,f[i]=s[i]=1;
			for(int j=i+1;j<=n;j++) d[j]=-1,f[j]=s[j]=0;
			for(int ti=1;ti<=n-i+1;ti++){
				int k=n;
				bool fl=true;
				for(int j=n;j>i;j--){
					while(k>1&&a[j]<=a[k-1]+m) k--;
					if(d[k]!=-1){
						d[j]=d[k]+1;
						if(s[k]!=f[j]) fl=false;
						f[j]=s[k];
					}
				}
				if(fl) break;
				int num=-1;
				for(int j=n;j>i;j--){
					if(d[j]>0){
						if(num==-1) num=j;
					}else continue;
					if(d[j]!=d[num]) break;
					if(f[j]==2) ans++;
				}	
				if(num==n) break;
				for(int j=n;j>i;j--){
					if(d[j]<=0) continue;
					if(f[j]==f[j+1]) s[j]=s[j+1]+1;
					else s[j]=1;
				}
			}
		}
		print(ans),putchar('\n');
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
