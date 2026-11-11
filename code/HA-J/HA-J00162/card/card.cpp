#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
deque<int> d;
bool b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		while(!d.empty()){
			b[d.front()]=false;
			d.pop_front();
		}
		for(int j=i; j<=n; j++){
			if(!b[a[j]]){
				d.push_back(a[j]);
				b[a[j]]=true;
			}
			else{
				while(d.back()!=a[j]){
					b[d.back()]=false;
					d.pop_back();
				}
			}
		}
		for(int j=1; j<=m; j++){
			if(b[j]) ans[j]++;
		}
	}
	for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
	return 0;
}
