#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace IO{
	bool Isdigit(char c){return c>='0'&&c<='9';}
	template<typename T>inline void read(T &x){
		char c=getchar();bool f=0;x=0;
		while(!Isdigit(c)){if(c=='-')f=1;c=getchar();}
		while(Isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
		x=f?-x:x;
	}
}
using namespace IO;
const int N=5e5+10;
ll n,m,a[N],Sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		Sum[i]=Sum[i-1]+a[i];
	int Ans=1;
	for(int i=2,l=1;i<=n;i++){
		while(l<i&&m<a[i]*(i-l)-Sum[i-1]+Sum[l-1])l++;
		Ans=max(Ans,i-l+1);
	}
	printf("%d\n",Ans);
}