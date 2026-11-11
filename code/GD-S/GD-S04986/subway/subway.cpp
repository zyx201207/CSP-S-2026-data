#include<bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define ff(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
long long ccccc,n,m,d,q,w[500001],k[501],a[501][20001],t[501][20001],x,y,s;
long long read(){
	int f=1;
	long long x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x<0)x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ccccc=read(),n=read(),m=read(),d=read(),q=read();
	f(i,1,m,1)cin>>w[i];
	f(i,1,n,1){
		k[i]=read();
		f(j,1,k[i],1)a[i][j]=read(),t[i][j]=read();
	}
	f(r,1,q,1){
		s=0;
		x=read(),y=read();
		long long x1[501],y1[501],z1[501],z=0;
		f(i,1,n,1){
			f(j,1,k[i],1){
				if(a[i][j]==y){
					bool xxx=0;
					f(asd,1,j-1,1){
						if(a[x1[z+1]][asd]==x)xxx=1,z=asd;
					}
					if(xxx==1)x1[++z]=i,y1[z]=j;
				}
			}
		}
		f(i,1,z,1){
			long long s1=0;
			f(j,z,y1[i],1){
				s1+=a[x1[i]][j];
			}
			s=max(s,s1);
		}
		cout<<s+w[1]+w[2]<<endl;
	}
	return 0;
}
