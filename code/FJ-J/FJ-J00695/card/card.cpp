#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,dis[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		deque<int> q;
		for(int j=i;j<=n;j++){
			int t;cin>>t;
			for(int k=0;k<q.size();k++){
				if(q[k]==t){
					for(int p=t;p<=n;p++){
						q.pop_back();
					}
				}
			}q.push_back(t);
		}for(int j=0;j<q.size();j++){
			dis[q[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<dis[i]<<' ';
	}return 0;
}
