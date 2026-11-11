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
	const intt N=5e5+10;
	intt A[N];
	inline void main(){
		intt n=read(),m=read();
		For(i,1,n)A[i]=read();
		sort(A+1,A+n+1);
		intt j=1,pre=A[1],Ans=1;
		For(i,2,n){
			while(A[i]*(i-j)-pre>m){
				pre-=A[j];j++;
			}
			pre+=A[i];
			Ans=max(Ans,i-j+1);
		}print(Ans);
		return;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Code::main();
	return 0;
}
