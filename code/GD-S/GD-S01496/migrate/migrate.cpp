#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll a[N],c[N],s[N];
int nxt[N];
vector<int>e[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int x=upper_bound(a+1,a+1+n,a[i]+d)-a;
			x--;
			nxt[i]=x; 
		}
		for(int i=1;i<=n;i++){
			e[nxt[i]].push_back(i); 
		}
		ll ans=0,res=0;
		int p=1;
		for(int i=1,j=0;i<=n;i++){
			while(j<=n&&nxt[j]<i){
				j++;
			}
			for(int u=0;u<e[i].size();u++){
				int y=e[i][u];
				if(y==i)continue;
				if(u>=2){
					c[y]=0;
					res-=s[y];
					c[i]++;
					s[y]=0;
				}else if(u==0){
					c[i]+=c[y];
					s[i]+=s[y];
					s[y]=0;
					c[y]=0;
				}else{
					s[i]+=c[y]-1;
					c[i]++;
					res+=c[y]-1;
					res-=s[y];
					c[y]=0;
					s[y]=0;
				}
			}
			c[i]++;
			ans+=res;
			if(j+1<i&&nxt[j+1]>i){
				ans+=max(c[j+1]-1,0ll);
			}
			if(nxt[i]==i){
				res=0;
				for(int u=p;u<=i;u++){
					s[u]=c[u]=0;
				}
				p=i;
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			nxt[i]=0;
			e[i].clear();
			c[i]=s[i]=0;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
5 3
-3 0 2 3 4

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/
