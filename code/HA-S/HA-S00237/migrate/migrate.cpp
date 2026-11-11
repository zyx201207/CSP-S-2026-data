#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define foru(a,b,c) for(ll a=b;a<=c;a++)
#define endl "\n"

ll c,t,n,m,a[5005],ans,cnt[5005][5005];
bool nw[5005];
vector<vector<ll> >e(5005);

void dfs(ll u,ll step){
	cnt[step][u]++;
	foru(i,u+1,n){
		if((a[i]-a[u])<=m)
		dfs(i,step+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>c>>t;
    while(t--){
    	cin>>n>>m;
    	foru(i,1,n){
    		cin>>a[i];
		}
//		foru(i,1,n){
//			e[i].clear();
//			foru(j,i+1,n){
//				if((a[j]-a[i])<=m){
//					e[i].push_back(j);
//				}else{
//					break;
//				}
//			}
//		}
		foru(i,1,n){
			nw[i]=0;
			foru(j,1,n){
				cnt[i][j]=0;
			}
		}
		dfs(1,1);
		foru(i,1,n){
			foru(j,1,n){
				if(cnt[i][j]){
					if(cnt[i][j]==2&&!nw[j]){
						ans++;
					}
					nw[j]=1;
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
