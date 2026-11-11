#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
bool vis[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		queue<int>q;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)	q.push(a[j]);
		stack<int>s;
		while(!q.empty()){
			int t=q.front();q.pop();
			if(vis[t]){
				bool flag=0;
				while(!s.empty()){
					if(s.top()==t){
						flag=1;
					}
					vis[s.top()]=0;
					s.pop();
					if(flag)	break;
				}
				s.push(t);
			}
			else	s.push(t);
			vis[t]=1;
		}
		while(!s.empty()){
			int t=s.top();s.pop();
			cnt[t]++;
		}
//		for(int i=1;i<=m;i++)	cout<<cnt[i]<<" ";
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)	cout<<cnt[i]<<" ";
	return 0;
}
