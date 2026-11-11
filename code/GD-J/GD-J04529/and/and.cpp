#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> a[35],c[35];
bool vis[N];
int n,m,b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>b[i];
		for(int j=30;j>=0;--j){
			if(b[i]&(1<<j)) a[j].push_back(i);
			else c[j].push_back(i);
		}
	}
	int ans=0;
	for(int i=30;i>=0;--i){
		int len=a[i].size();
		int sum=0;
		for(int j=0;j<len;++j){
			if(!vis[a[i][j]]) ++sum;
		}
		if(sum>=m){
			ans|=(1<<i);
			len=c[i].size();
			for(int j=0;j<len;++j) vis[c[i][j]]=1;
		}
	}
	cout<<ans;
	return 0;
}
