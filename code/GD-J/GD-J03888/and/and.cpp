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
const int N=2e3+100;
int n,m,li[N],f[N][N],jl[35][N],s[35];
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	n=read();m=read();
	int ma=0,u=0;
	for (int i=1;i<=n;i++){
		li[i]=read();
		if (i==1) u=li[i];
		else u&=li[i];
		ma=max(li[i],ma);
//		f[i][0]=li[i];
//		for (int j=0;j<=30;j++){
////			cout<<"j:"<<(1<<j)<<'\n';
//			if (li[i]&(1<<j)){
//				jl[j][++s[j]]=li[i];
//			}
//		}
	}
	if (m==1){
		write(ma);putchar('\n');
		return 0;
	}
//	if (m==n){
//		write(u);putchar('\n');
//		return 0;
//	}
	if (m==2){
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				ans=max(ans,(li[i]&li[j]));
			}
		}
		write(ans);putchar('\n');
		return 0;
	}
	bool r=true;
	for (int i=1;i<=n;i++){
		bool w=false;
		for (int j=31;j>0;j--){
			if (li[i]==(1<<j)-1){
				w=true;
				break;
			}
		}
		if (!w){
			r=false;
			break;
		}
	}
	if (r){
		sort(li+1,li+1+n,cmp);
		int u=li[1];
		for (int i=2;i<=m;i++){
			u&=li[i];
		}
		write(u);putchar('\n');
		return 0;
	}
	r=true;
	for (int i=1;i<=n;i++){
		if (li[i]!=i-1){
			r=false;
			break;
		}
	}
	if (pow(2,(int)log2(n))==n&&r){
		cout<<pow(2,log2(n)-m+1)<<'\n';
		return 0;
	} 
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=1;k<i;k++){
				if (j==2) f[i][j]=max(f[i][j],(li[k]&li[i]));
				else f[i][j]=max(f[i][j],(f[k][j-1]&li[i]));
			}
		}
	}
	write(f[n][m]);putchar('\n');
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

5 4
4 5 3 6 7
*/
