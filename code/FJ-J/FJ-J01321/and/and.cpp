#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[35];
int a[1000000];
vector<int> ll[35];
int n,m,l=0,num=0;
int dfs(int x,int k,int sum,int b){
	if(b==m)return sum;
	if(b+ll[x].size()-k<=m||sum<=num)return 0;
	for(int i=k+1;i<ll[x].size();++i){
		return dfs(x,i,(sum&ll[x][i]),b+1);
	}
}
void ans(int s){
	sort(ll[s].begin(),ll[s].end(),greater<int>());
	for(int i=0;i<ll[s].size();++i){
		num=max(dfs(s,i,ll[s][i],1),num);
	}
	cout<<num;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int j=1;j<=n;++j){
		int x;
		cin>>x;
		a[j]=x;
		for(int i=0;x;++i){
			if(x%2==1)arr[i]++;
			x/=2;
			l=max(l,i);
			ll[i].push_back(a[j]);
		}
	}
	for(int i=l;i>=0;--i){
		if(arr[i]>=m){
			ans(i);
			return 0;
		}
	}
	cout<<0;
	return  0;
}
