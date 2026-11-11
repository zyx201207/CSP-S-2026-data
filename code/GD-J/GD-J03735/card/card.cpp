#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	vector<int> ans(m+1);
	vector<bool> visn(m+1);
	for(int k=1;k<=n;k++){
		deque<int> q;
		for(int i=1;i<=m;i++) visn[i]=false;
		for(int i=k;i<=n;i++){
			if(!visn[a[i]]){
				q.push_back(a[i]);
				visn[a[i]]=true;
			}else{
				while(q.back()!=a[i]){
					visn[q.back()]=0;
					q.pop_back();
				}
			}
		}
		while(!q.empty()){
			ans[q.front()]++;
			q.pop_front();
		}
	}for(int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
