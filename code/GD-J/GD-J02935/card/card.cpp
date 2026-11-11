#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define ll long long
inline ll read(){
	ll f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=5e5+10;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int gm=1;gm<=n;gm++){
		vector<int> vis(n+2);
		for(int i=gm;i<=n;i++){
			vis[i]=1;int lst=0;
			for(int j=i-1;j>=gm;j--){
				if(vis[j]==1&&a[j]==a[i]){lst=j;break;} 
			}
			if(!lst) continue;
			for(int j=i-1;j>=lst;j--){
				vis[j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(!ans[a[i]]) ans[a[i]]+=vis[i];
		} 
	}
	for(int i=1;i<=m;i++) write(ans[i]),putchar(' ');
	return 0;
}
