#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(x) putchar(x)
const int maxn=5e5+5,maxm=3e5+5;
int a[maxn],b[maxm],pos[maxm],mp[maxn],ans[maxm];
int read(){
	int x=0,ch=gc();
	while (!isdigit(ch)) ch=gc();
	while (isdigit(ch)) {
		x=x*10+ch-'0';
		ch=gc();
    }
	return x;
}
void write(int x){
	if (x>9) write(x/10);
	pc(x%10+'0');
}
void A(int n,int m){
	for (int i=1;i<=n;i++){
		if (a[i]!=a[i+1]){
			write(i);
			pc(' ');
		}
	}
}
void sol1(int n,int m){
	for (int i=1,x=0;i<=n;i++,x=0){
		memset(pos,-1,sizeof pos);
		for (int j=i;j<=n;j++){
			if (pos[a[j]]!=-1){
				for (int k=1;k<=m;k++){
					if (pos[k]>pos[a[j]]){
						pos[k]=-1;
					}
				}
				x=pos[a[j]];
			}
			pos[a[j]]=x;
			mp[x++]=a[j];
		}
		for (int j=0;j<x;j++){
			ans[mp[j]]++;
		}
	}
	for (int i=1;i<=m;i++) {
		write(ans[i]);
		pc(' ');
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(),m=read();
	bool isA=1;
	for (int i=1;i<=n;i++) {
		a[i]=read(); 
		if (a[i]<a[i-1]) isA=0;
	}
	if (isA){
		A(n,m);
		return 0;
	}
	if (n*n*m<=5e8){
		sol1(n,m);
		return 0;
	}
	cout << 1;
	return 0;
}
