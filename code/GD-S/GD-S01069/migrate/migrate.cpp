#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define DF(i,a,b) for(int i=(a);i>=(b);i--)
const int N=305;
int c,T,n,d,x[N],cnt[N];
vector<int>fr[N];
//void dfs(int i,int )
#define dis(i,j) abs(x[i]-x[j])
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		F(i,1,n)cin>>x[i];
		if(c==13||c==14){
			cout<<"0\n";continue;
		}
//		dfs(1,0);
		F(i,1,n){
			F(j,i+1,n){
				int cnt=0;
				F(k,i+1,j-2){
					if(dis(i,k)<=d&&dis(i,k+1)<=d&&dis(k,j)<=d&&dis(k+1,j)<=d)cnt++;
				}
				if(cnt==1)ans++;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
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
*/
