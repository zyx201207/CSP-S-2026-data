#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N=1e6+5;
inline LL read(){
	LL res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	if(f==1) return res;
	return -res;
}
int n,k,u[N],v[N];
void init(){
	n=read(),k=read();
	for(int i=1;i<n;i++) u[i]=read(),v[i]=read();
}
void solveA(){
	int m=n/2,ans=0;
	if(k==n) ans=0;
	else if(k>=m) ans=1;
	else{
		int x=(m+1)/2;
		ans=(x-k/2+1)/2+1;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		init();
		solveA();
	}
	return 0;
}
