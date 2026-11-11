#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
long long RP=0;
#define INF 11936520
#define xzr 20110420
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
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	RP+=INF;
	if(c>=11&&c<=12){
		while(t--){
			int n=read(),d=read();
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++)a[i]=read();
			int del=a[2]-a[1];
			int tmp=1;
			for(int i=1;i<=n;i++){
				if(i*del<=d)tmp=i;
				else break;
			}
			if(del>=d)cout<<0<<endl;
			else cout<<(n-1)*(n-2)/2<<endl;
		}
	}else
	{
		while(t--){
			cout<<0<<endl;
		}
	}
	//徐子冉520 jr99
	return 0;
}
