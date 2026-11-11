#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int cp[2000006];
int vj[2000006];
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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read();
	t = read();
	while(t--){
		n = read();
		d = read();
		memset(cp,0,4*n+160);
		memset(vj,0,4*n+160);
		for(int i = 1;i<=n;i++){
			cp[i] = read();
			vj[i] = cp[i]+d;
		}
		int todp = 0;
		int ans = 0;
		todp = 1;
		for(int i = 1;i<=n;i++){
			int keys = cp[i];
			int *bb = lower_bound(vj+todp,vj+i+1,keys);
			int yyp = bb-vj;
			todp = yyp;
			if(i-yyp == 2){
				ans++;
			}
		}
		cout<<ans-1<<"\n";
	}
}
