#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
long long ans=0;
bool vis[N];
vector<int>f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=true;
	}
	for(int j=30;j>=0;j--){
		f.clear();
		int cnt=0,cntl=0;
		for(int i=1;i<=n;i++){
			if(!vis[i])	continue;
			if((a[i]>>j)&1){
				cntl++;
			}
			else{
				cnt++;
				f.push_back(i);
			}
		}
		if(cntl>=m){
			ans|=(1<<j);
			for(int i=0;i<f.size();i++){
				vis[f[i]]=false;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
4 2
3 15 12 12
12

5 3
31 3 1 15 7
7
*/
