#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[35],maxn=-1;
vector<int> vec[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	b[0]=1;
	for(int i=1;i<=30;i++)  b[i]=b[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if(a[i]&b[j]){
				vec[j].push_back(i);
				if(vec[j].size()>=m)  maxn=max(maxn,j);
			}
		}
	}
	int ans=b[maxn];
	for(int i=maxn-1;i>=0;i--){
		int cnt=0;
		queue<int> q;
		for(int j=0;j<vec[maxn].size();j++)if(a[vec[maxn][j]]&b[i])cnt++,q.push(vec[maxn][j]);
		if(cnt>=m){
			ans+=b[i];
			vec[maxn].clear();
			while(q.size())vec[maxn].push_back(q.front()),q.pop();
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
