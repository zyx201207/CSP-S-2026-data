#include<bits/stdc++.h>
using namespace std;
#define intt long long
namespace IO{
	inline intt read(){
		intt x=0,f=1;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
		for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
		return x*f;
	}
	inline void write(intt x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+'0');return;
	}
	inline void print(intt x,bool fl=1){
		write(x);if(fl)putchar('\n');
		else putchar(' ');return;
	}
}using namespace IO;
namespace Code{
	#define For(i,a,b) for(int i=(a);i<=(b);i++)
	#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
	#define pb push_back
	#define mk make_pair
	typedef pair<intt,intt>PII;
	typedef vector<intt>Vntt;
	const intt N=2e6+10;
	intt A[N],fa[N],dep[N],ans[N],pre[N];
	inline void main(){
		intt n=read(),d=read();
		For(i,1,n)A[i]=read();
		For(i,1,n)fa[i]=dep[i]=ans[i]=pre[i]=0; 
		fa[1]=0;
		intt j=1,lst=1;
		A[n+1]=A[n+2]=1e18;
		For(i,2,n){
			while(A[i]-A[j]>d)j++;
			if(j==i){
				lst=i;fa[i]=0;
				continue;
			}
			fa[i]=j;
			if(j==i-1){
				ans[i]=ans[j];
				continue;
			}
			intt L=A[j+1]-d,R=A[j]-1;
			if(j+2<=i)R=min(R,A[j+2]-d-1);
			intt cnt=0,k=0;
			Rep(i,j-1,lst){
				if(A[i]>=L&&A[i]<=R){
					cnt++;k=i;
				}if(A[i]<L)break;
			}
			ans[i]=cnt;
			if(k-fa[j]>=2)ans[i]+=ans[j];
			intt res=0,p=k;
			while(k>lst&&(fa[k]!=fa[k+1])){
				if(pre[k]){
					res+=pre[k];
					break;
				}
				res+=fa[k+1]-fa[k];
				k=fa[k];
			} 
			pre[p]=res;
			ans[i]+=res;
		}
		intt Ans=0;
		For(i,1,n)Ans+=ans[i];
		print(Ans,1); 
		return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	intt c=read(),t=read();
	while(t--)Code::main();
	return 0;
}

