#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool f[200005];

int read(){
	int num=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		num=(num<<1)+(num<<3)+(ch^48);
		ch=getchar();
	}
	return num;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=30;i>=0;i--){
		int num=0;
		for(int j=1;j<=n;j++) if(!f[j]&&((a[j]>>i)&1)) num++;
		if(num<m) continue;
		ans+=(1<<i);
		for(int j=1;j<=n;j++) if(!((a[j]>>i)&1)) f[j]=1;
	}
	cout<<ans;
	return 0;
}
