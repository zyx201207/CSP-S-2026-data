#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define int long long
#define IOimprove ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;T f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,k,x,ans=0,bit[222222][33];
signed main(){
	file("and")
	read(n);read(k);
	for(int i=1;i<=n;i++){
		read(x);
		for(int j=0;j<=30;j++){
			if(x&1)bit[i][j]=1;
			x>>=1;
		}
	}
	vector<int>v,w;v.clear();
	for(int i=1;i<=n;i++)v.push_back(i);
	for(int j=30;j>=0;j--){
		w.clear();int g=0;
		for(int i:v)
			if(bit[i][j]==1)w.push_back(i),g++;
		if(g<k)continue;
		ans+=(1<<j);v.clear();
		for(int h:w)v.push_back(h);
	}
	write(ans);puts("");
	return 0;
}
