#include<bits/stdc++.h>
using namespace std;
vector<int> nw,nxt;
int n,m,a,cnt;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		nw.push_back(a);
	}
	int ans=0;
	for(int j=29;j>=0;j--){
		cnt=0;
		for(int i=0;i<(int)(nw.size());i++){
			if(nw[i]&(1<<j)){
				cnt++;
			}
		}
		if(cnt>=m){
			ans|=(1<<j);
			nxt.clear();
			for(int i=0;i<(int)(nw.size());i++){
				if(nw[i]&(1<<j)){
					nxt.push_back(nw[i]);
				}
			}
			swap(nw,nxt);
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}