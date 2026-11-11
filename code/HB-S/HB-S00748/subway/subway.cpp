#include<bits/stdc++.h>
using namespace std;

int read(){
	int w = 1,s = 0;
	char ch = getchar();
	while(ch<48||ch>57){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch>=48&&ch<=57){
		s = (s<<1)+(s<<3)+(ch^48);
		ch = getchar();
	}
	return w*s;
}

const int N = 5e5+10,M = 510;

int c,n,m,d,q,w[N],k[M],ch[N][M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i <= m;++i)w[i] = read();
	for(int i = 1;i <= n;++i){
		k[i] = read();
		for(int j = 1;j <= k[i];++j){
			int a = read(),b = read();	
		}
	}
	for(int i = 1;i <= q;++i){
		int l = read(),r = read();
		cout<<w[l]+w[r]<<endl;
	}
	return 0;
}