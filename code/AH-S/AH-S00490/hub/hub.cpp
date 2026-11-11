#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked

inline int read(){
	int x=0,v=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')v=-1;
		ch=gc();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+(ch-'0');
		ch=gc();
	}
	return x*v;
}

const int N=1e6+5;
int c,t;
int n,k;
vector <int> to[N];

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n-1;i++){
			int u=read(),v=read();
			to[u].push_back(v);
			to[v].push_back(u);
		}
		int m=(n-1)>>1;
		int x=m>>1,y=m>>2;
		if(k==1){
			cout<<x+1<<'\n';
		}
		else if(k==2||k==3){
			cout<<x-y+1<<'\n';
		}
		else{
			if(m%4!=0)cout<<x-y+1<<'\n';
			else cout<<x-y<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

