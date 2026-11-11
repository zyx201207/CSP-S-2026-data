#include<bits/stdc++.h>
using namespace std;

//////WARNING////// x>=0 
template<typename T>
inline void read(T &x){
	char c=getchar();x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c&15),c=getchar();
}

template<typename T>
inline void write(T x){
	if(!x)return putchar('0'),void();
	if(x/10)write(x/10);
	putchar('0'|(x%10));
} 

const int maxn=5e5+15;
#define ll long long
int n,m,q,a[maxn];
vector<pair<int,int> > v[maxn],train[550];

// 550W MOSS ÇãÇé´´×÷ 
ll f[550][550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	read(n);read(n);read(m);read(q);read(q);
	for(int i=1;i<=m;++i)read(a[i]),v[i].reserve(20);
	for(int i=1,k;i<=n;++i){
		f[i][i]=0;
		read(k);
		train[i].resize(k);
		for(pair<int,int> &x:train[i]){
			read(x.first);read(x.second);
			for(pair<int,int> t:v[x.first]){
				f[i][t.first]=f[t.first][i]=min(f[t.first][i],1ll*t.second+x.second);
			}
			v[x.first].push_back({i,x.second});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)
			f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	}
	for(int i=1,s,t;i<=q;++i){
		read(s);read(t);
		ll ans=9e18;
		for(pair<int,int> x:v[s])for(pair<int,int> y:v[t]){
			ans=min(ans,f[x.first][y.first]+x.second+y.second);
		}
		ans+=a[s]+a[t];
		write(ans);putchar('\n'); 
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

