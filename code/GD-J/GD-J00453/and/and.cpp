#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n,m;
int a;
vector<int> b[100005];
int main(){
	fastio;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=30;j>=0;j--){
			if((x>>j)&1) b[j].push_back(x);
		}
	}
	for(int i=30;i>=0;i--){
		if((int)b[i].size()>=m){
			sort(b[i].begin(),b[i].end(),greater<int>());
			int ans=b[i][0];
			for(int j=1;j<m;j++){
				ans&=b[i][j];
			}
			cout<<ans;
			break;
		}
	}
	return 0;
}
