#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
bool nd[N];
int ans=0;
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(nd,true,sizeof(nd));
	vector<int> nw;
	for(int i=30;i>=0;i--){
		nw.clear();
		for(int j=1;j<=n;j++){
			if(!(a[j]&(1<<i))){
				if(nd[j]){
					nw.push_back(j);
				}
				nd[j]=false;
			}
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(nd[j]){
				cnt++;
			}
		}
		if(cnt>=m){
			ans|=(1<<i);
		}else{
			int p=nw.size();
			for(int j=0;j<p;j++){
				int res=nw[j];
				nd[res]=true;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;	
}
