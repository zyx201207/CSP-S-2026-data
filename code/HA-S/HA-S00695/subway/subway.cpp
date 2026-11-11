#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int tu[500005];
int xm[505];
int lxm[505];
int matu[5505][5505];
int read(){
	int g = 0,f = 1;
	char h = getchar();
	while(h<'0'||h>'9'){
		if(h == '-'){
			f = -1;
		}
		h = getchar();
	}
	while((h>='0')&&(h<='9')){
		g*=10;
		g+=(h-'0');
		h = getchar();
	}
	return f*g;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();n = read();m = read();d = read();q = read();
	for(int i = 1;i<=m;i++){
		tu[i] = read();
	}
	for(int i = 1;i<=n;i++){
		xm[i] = read();
		lxm[i] = read();
		matu[xm[i]][m+i] = lxm[i];
		matu[m+i][xm[i]] = lxm[i];
	}
	for(int i = 1;i<=m;i++){
		for(int k = m+1;k<m+n;k++){
			for(int j = j+1;j<m;j++){
				if(matu[i][k]&&matu[k][j]){
					matu[i][j] = min(matu[i][j],matu[i][k]+matu[k][j]);
				}
	}
	}
	}
	for(int i = 1;i<=q;i++){
		int x,y;
		x= read();
		y = read();
		int ans = tu[x]+tu[y];
		cout<<ans+matu[x][y]<<"\n";
	}
}

