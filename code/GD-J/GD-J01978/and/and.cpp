#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n=read(),m=read();
	for(int i=0;i<n;i++)a[i]=read();
	sort(a,a+n);
	printf("%d",a[n-m]);
	return 0;
}
