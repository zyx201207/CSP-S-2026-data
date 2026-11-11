#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,ans[N],a[N];
bool st[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> q;
		memset(st,0,sizeof(st));
		for(int j=i;j<=n;j++){
			if(st[a[j]]==true){
				while(st[a[j]]==true) {
					st[q.top()]=false;
					//cout<<st[2]<<' ';
					q.pop();
				}
			}
			q.push(a[j]);
			st[a[j]]=true;
		}
		//while(!q.empty()){cout<<q.front()<<' ';q.pop();}
		//cout<<'\n';
		for(int j=1;j<=m;j++) if(st[j]) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

