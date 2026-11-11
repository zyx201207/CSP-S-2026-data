#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
vector<int>nw,nxt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		nw.push_back(a[i]);
	}
	for(int i=30;i>=0;--i){
		int tot=0;
		nxt.clear();
		for(int j=0;j<(int)nw.size();++j){
			if(nw[j]&(1<<i)){
				++tot;
				nxt.push_back(nw[j]);
			}
			
		}
		if(tot>=m){
			ans+=(1<<i);
			nw=nxt;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
