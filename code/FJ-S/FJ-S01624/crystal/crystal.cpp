#include<bits/stdc++.h>
#define int long long
using namespace std;int read();
const int N=500005;
int n,m,a[N],b[N],res;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	for(int i=1,j=1;i<=n;i++){
		while(a[i]*(i-j+1)-(b[i]-b[j-1])>m) j++;
		res=max(res,i-j+1);
	}printf("%lld\n",res);
	return 0;
}
int read(){
	int Ca=0,Cf=1;char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-Cf;}}
	while(Cr>='0' && Cr<='9'){Ca=Ca*10+(Cr-'0');Cr=getchar();}
	return Ca*Cf;
}
