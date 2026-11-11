#include <bits/stdc++.h>
#define endl putchar('\n')
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int read(){
	char c=getchar();
	int x=0;bool flag=false;
	while(c>'9' || c<'0'){
		if(c=='-') flag=true;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return flag ? -x : x;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=5e5+5, M=3e5+5;
int a[N], ans[M], id[M], flag[N];
bool f[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(), m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) flag[j]=0;
		for(int j=1;j<=m;j++) id[j]=0, f[j]=false;
		for(int j=i;j<=n;j++){
			if(!id[a[j]]) id[a[j]]=j;
			else{
				flag[id[a[j]]]=j;
				id[a[j]]=j;
			}
		}
		for(int j=i;j<=n;){
			if(flag[j]){
				j=flag[j];
			}
			else{
				if(!f[a[j]] && id[a[j]]) ans[a[j]]++;
				f[a[j]]=true;
				j++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		write(ans[i]);putchar(' ');
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
