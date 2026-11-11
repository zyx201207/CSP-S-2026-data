#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
int c,T;
int a[N],tot[N],up[N],len[N],lst[N];
bool u[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>T;
	while(T--){
		int n,d;
		bool flag=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=3;i<=n;i++)
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=1;
		if(!flag){
			int cha=a[2]-a[1],L=d/cha*2-1;
			if(L<=1||n-L<1) cout<<0<<endl;
			else cout<<n-L<<endl;
			continue;
		}
		int now=1;
		for(int i=1;i<=n;i++){
			while(now<n&&a[now+1]-a[i]<=d) now++;
			up[i]=now;
		}
		for(int i=n;i>=1;i--){
			if(up[i]==i||up[i]==up[i-1]) continue;
			u[i]=1;
			len[i]=len[up[i]]+up[i]-i;
		}
		int ans=0,NOW=0;
		for(int i=1;i<=n;i++){
			if(u[i]) lst[i]=NOW,NOW=i;
		}
		for(int i=n;i>=1;i--){
			if(up[i]==i) continue;
			if(u[up[i]]) tot[i]+=tot[up[i]];
			if(up[i]==i+1) continue;
			if(!u[up[i]-1]) continue;
			tot[i]+=len[up[i]-1]-1;
			if(lst[up[i]-1]!=i) tot[i]-=up[lst[up[i]-1]]-up[i];
		}
		for(int i=1;i<=n;i++) ans+=tot[i];
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) tot[i]=a[i]=lst[i]=up[i]=len[i]=0,u[i]=0;
	}
	return 0;
}
/*
0 1
6 12
-10 -6 -2 2 6 10


4 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 1000000000000000000

0 1
5 3
-3 0 2 3 4

*/
