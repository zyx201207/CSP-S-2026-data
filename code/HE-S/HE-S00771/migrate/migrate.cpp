#include<cstdio>
#include<algorithm>
#include<iostream>
namespace IO{
	#define CH getchar
	template <typename T>
	inline T read(){
		T f=1,x=0;
		char c=CH();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=CH();}
		while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=CH();
		return f*x;
	}
	#define PUT putchar
	template <typename T>
	inline void write(T x){
		if(x==0){PUT('0');return;}
		if(x<0){PUT('-');x=-x;}
		int sta[40],top=0;
		while(x)sta[top++]=x%10,x/=10;
		while(top)PUT(sta[--top]+'0');
	}
	template <typename T>
	inline void print(T x){write(x);PUT('\n');}
}
#define int long long 
using namespace std;
using namespace IO;
const int N=2e6+5;
int n,d;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read<int>(),t=read<int>();
	while(t--){
		n=read<int>(),d=read<int>();
		for(int i=1;i<=n;i++)a[i]=read<int>();
		int xi=a[2]-a[1];
		if(n>=4&&2*xi<=d&&3*xi>d)print<int>(n-4+1);
		else print(0);
	}	
	return 0;
}
