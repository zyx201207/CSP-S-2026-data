#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> vec(n+1);
	for(int i=1;i<=n;i++) cin>>vec[i];
	unordered_map<int,int> ans;
	for(int i=1;i<=n;i++){
		unordered_map<int,int> now;
		for(int j=i;j<=n;j++){
			if(now[vec[j]]==0) now[vec[j]]=j;
			else{
				int idx=now[vec[j]];
				for(auto t:now){
					if(t.second>idx) now[t.first]=0;
				}
			}
		}
		for(auto x:now){
			if(x.second>0) ans[x.first]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
