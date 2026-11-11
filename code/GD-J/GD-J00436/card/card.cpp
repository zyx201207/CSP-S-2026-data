#include <iostream>
#include <map>
#include <stack>
using namespace std;
void js(){
	ios::sync_with_stdio(0);
	cin.tie(0);
}
const int N=5e5+10;
int n,m,a[N];
map<int,int> f;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	js();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		map<int,int> mp;
		stack<int>q;
		for(int j=i;j<=n;j++){
			if(!mp[a[j]]){
				mp[a[j]]=1;
				q.push(a[j]);
			}
			else{
				while(!q.empty()&&q.top()!=a[j]){
					mp[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			f[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<f[i]<<' ';
	return 0;
}
