#include <bits/stdc++.h> 
using namespace std;
const long long N=5e5+78;
deque <long long> tab;
long long n,m,a[N],ans[N],tabi[N];
void dfs(long long x){
	for(long long i=x;i<=n;i++){
		tab.push_back(a[i]);
		tabi[a[i]]++;
		if(tabi[a[i]]>1){
			tabi[tab.back()]--;
			tab.pop_back();
			while(tab.back()!=a[i]){
				tabi[tab.back()]--;
				tab.pop_back();
			}	
		}
	}
	for(int i=1;i<=m;i++){
		if(tabi[i]>0){
			ans[i]++;
			tabi[i]=0;
		}	
	}
	while(!tab.empty()){
		tab.pop_back();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		dfs(i);
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
