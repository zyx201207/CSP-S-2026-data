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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}

//我常常 追忆过去
//我不想和我的朋友分别
//我不想倒开 
//这一生我要和多少人离别？
//要是能常常见面就好了
//要是能再见你一面就好了
//我要上迷惑行为大赏
//T4我不会写 
