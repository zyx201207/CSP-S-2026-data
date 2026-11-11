#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],st[500010],ss[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	stack<int>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)ss[j]=0;
		for(int j=i;j<=n;j++){
			if(ss[a[j]]==0){
				ss[a[j]]=1;
				q.push(a[j]);
			}
			else{
				while(q.size()&&q.top()!=a[j])q.pop();
			}
		}
		while(q.size()){
			st[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<st[i]<<' ';
	return 0;
}
