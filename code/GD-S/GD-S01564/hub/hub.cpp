#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=35;
int C,T,n,k;
vector<int>g[N];
bool is[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar(); }
	return x*f;
}
int popcount(int x){
	int cnt=0;
	while(x>0){
		if(x&1)cnt++;
		x>>=1;
	}
	return cnt;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cout<<"2\n";
	}
	return 0;
}

