#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e5+10;
int n,m;
vector<int> a;
queue<int> q[N];
int ans[N];
vector<int> e;

signed main(){
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int num;cin>>num;
		a.push_back(num);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)while(q[j].size())q[j].pop();
		for(int j=i-1;j<n;j++){
			int ed=a[j];
			if(q[ed].size()!=0){
				int t=q[ed].front();
				for(int k=t;k<j;k++){
					if(q[a[k]].size())q[a[k]].pop();
					else break;
				}
			}
			q[ed].push(j);
		}
		for(int i=1;i<=m;i++)if(q[i].size())ans[i]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
