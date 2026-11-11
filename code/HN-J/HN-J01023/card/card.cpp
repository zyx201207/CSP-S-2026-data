#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[1000010];
map<int,int> b;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int j=1; j<=n; j++){
		deque<int> q;
		map<int,int> p;
		for(int i=j; i<=n; i++){
			if(p[a[i]]==0){
				q.push_back(a[i]);
				p[a[i]]++;
			}else{
				while(q.back()!=a[i]){
					int t=q.back();
					p[t]--;
					q.pop_back();
				}
			}
		}
		while(q.size()){
			b[q.back()]++;
			q.pop_back();
		}
	}
	for(int i=1; i<=m; i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
