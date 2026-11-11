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
using namespace std;
using namespace IO;
typedef long long ll;
const int N=5e5+5;
int n,ret;
ll m;
ll a[N],pre[N];
int lf,rt;
bool check(int x){
	for(int i=x;i<=n;i++){
		ll c=1ll*x*a[i];
		ll d=pre[i]-pre[i-x];
		if(c-d<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read<int>();m=read<ll>();
	for(int i=1;i<=n;i++)a[i]=read<ll>();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	//for(int i=1;i<=n;i++)cout<<pre[i]<<" ";
	//PUT('\n');
	lf=1,rt=n;
	while(lf<=rt){
		int mid=(lf+rt)>>1;
		//cout<<mid<<"\n";
		if(check(mid))ret=mid,lf=mid+1;
		else rt=mid-1;
	}
	print<int>(ret);
	return 0;
}
//end at 15:10
//Bob jiu wo gou ming -Wall tai qiang le
