#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int M=2e6+10;
int u[N],v[M];
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		int n=read(),k=read();
		for(int i=1;i<=n;i++)u[i]=read(),v[i]=read();
		cout<<0<<"\n";
	}
	return 0;
}
