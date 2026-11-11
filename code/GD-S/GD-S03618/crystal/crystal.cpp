#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	return x*f;
}
const int N=5e5+10;
int n,m;
int len,flen;
int a[N],s[N];
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(i-(len+1)>=0&&m+(s[i]-s[i-(len+1)])>=a[i]*(len+1))len++;
//		if(len>0)len--;
//		flen=max(flen,len);
//		cout<<i<<" "<<len<<endl;
	}
	cout<<len;
	return 0;
}
