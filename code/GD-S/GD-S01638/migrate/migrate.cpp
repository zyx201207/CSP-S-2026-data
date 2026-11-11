#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+7;
struct dd{
	int x,w;
};

int n,d,x[N],a[N],b[N],ans,c[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int asc,T;
	cin>>asc>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}deque<dd>q;
		for(int k=1;k<=n-1;k++){
			q.clear();
			memset(a,0,sizeof(a)); 
			memset(b,0,sizeof(b)); 
			memset(c,0,sizeof(c)); 
			b[0]++;c[k]=0;
			q.push_back({0,k});
			for(int i=k+1;i<=n;i++){
				while(x[i]-x[q.front().w]>d){
					b[q.front().x]--;
					q.pop_front();
				}
				c[i]=b[q.front().x];
				b[(q.front().x+1)]++;
				q.push_back({(q.front().x+1),i});
			}
			for(int i=1;i<=n;i++){
				if(c[i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
}/*
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

*/
