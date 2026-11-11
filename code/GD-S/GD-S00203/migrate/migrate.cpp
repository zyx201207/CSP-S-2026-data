#include<bits/stdc++.h>
using namespace std;

template<typename T>
inline void read(T &x){
	char c=getchar();x=0;int flag=1;
	while(!isdigit(c)){
		if(c=='-')flag=-1;
		c=getchar();
	}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c&15),c=getchar();
	x*=flag;
}
template<typename T>
inline void write(T x){
	if(!x)return putchar('0'),void();
	if(x/10)write(x/10);
	putchar('0'|(x%10));
} 

const int maxn=2e6+15;
#define ll long long
int n,f[maxn],g[maxn],dpf[maxn],dpg[maxn];
pair<int,int> rgf[maxn],rgg[maxn];
inline void upd(pair<int,int> &t,const int &x){
	t.first=min(t.first,x);
	t.second=max(t.second,x);
}
inline int calc(const pair<int,int> &x,const pair<int,int> &y){
	return max(0,min(x.second,y.second)-max(x.first,y.first)+1);
}
ll d,a[maxn];
void solve(){
	read(n);read(d);
	for(int i=1;i<=n;++i)read(a[i]),rgf[i]=rgg[i]={n+1,-1};
	for(int i=1,t=1;i<=n;++i){
		while(a[t]<a[i]-d)++t;
		g[i]=t;
	}
	for(int i=n,t=n;i;--i){
		while(a[t]>a[i]+d)--t;
		f[i]=t;
	}
	for(int i=1;i<=n;++i){
		upd(rgg[g[i]],i);
		upd(rgf[f[i]],i);
	}
	for(int i=1;i<=n;++i){
		if(g[i]==i||f[g[i]]!=i)dpg[i]=1;
		else dpg[i]=dpg[g[i]]+1;
		if(g[i]!=i){
			dpg[i]+=calc(rgf[i],{1,i-1})-1;
			if(f[g[i]]!=i)dpg[i]++;
		}
	}
	for(int i=n;i;--i){
		if(f[i]==i||g[f[i]]!=i)dpf[i]=1;
		else dpf[i]=dpf[f[i]]+1;
		if(f[i]!=i){
			dpf[i]+=calc(rgg[i],{i+1,n})-1;
			if(g[f[i]]!=i)dpf[i]++;
		}
	}
	ll ans=0;
	for(int i=3;i<n;++i){
		if(a[i-1]+d<a[i])continue;
		int L=calc(rgf[i],{1,i-2});
		if(g[i-1]<i-1&&f[g[i-1]]==i)L+=dpg[g[i-1]]-1;
		int R=calc(rgg[i-1],{i+1,n});
		if(f[i]>i&&g[f[i]]==i-1)R+=dpf[f[i]]-1;
		ans+=1ll*L*R;
	}
	write(ans);putchar('\n');
}
int main(){
//	freopen("down/migrate/migrate5.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int tc=(read(tc),read(tc),tc);tc--;)solve();
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
4 2
1 2 3 4

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 633
-1000 -558 -116 105 326 547 989

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
6

0 1
5 3
1 2 3 4 5
0
*/

