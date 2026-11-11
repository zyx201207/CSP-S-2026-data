#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int st[N];
int ans[N];
bool ch[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		deque<int> q;
		memset(st,0,sizeof st);
		memset(ch,0,sizeof ch);
		for(int j=i;j<=n;j++){
			if(!st[a[j]]){
				q.push_back(a[j]);
				st[a[j]]++;
			}
			else{
				while(q.back()!=a[j]){
					int x=q.back();
					st[x]--;
					q.pop_back();
				}
			}
		}
		while(!q.empty()){
			int x=q.front();
			if(!ch[x]){
				ans[x]++;
				ch[x]=1;
			}
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
 	return 0;
}
