#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		queue<int> p;
		bool v[500010]={0};
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0) v[a[j]]=1;
			else {
				while(!p.empty()) p.pop();
			}
			p.push(a[j]);
		}
		while(!p.empty()){
			ans[p.front()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
