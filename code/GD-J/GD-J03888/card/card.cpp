#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline int read(){
	int a=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		a=(a<<3)+(a<<1)+(ch-'0');
		ch=getchar();
	}
	return a*f;
}
inline void write(int a){
	if (a<0){
		a=-a;
		putchar('-');
	}
	if (a>=10) write(a/10);
	putchar(a%10+'0');
}
const int N=2e5+100;
int n,m,li[N],v[N],ans[N];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		li[i]=read();
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			v[j]=li[j];
			for (int k=i;k<j;k++){
				if (v[k]==li[j]){
					for (int l=k;l<j;l++) v[l]=0;
				}
			}
		}
//		for (int j=i;j<=n;j++) cout<<v[j]<<' ';
//		cout<<'\n';
		for (int j=i;j<=n;j++){
			ans[v[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
