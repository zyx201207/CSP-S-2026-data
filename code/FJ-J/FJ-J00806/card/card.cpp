#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],ans[M];
bool book[M];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		q.push(a[i]);
		if(!book[a[i]])
			book[a[i]]=true;
		else if(book[a[i]]){
			while(q.top()!=a[i]){
				book[q.top()]=false;
				q.pop();
			}
		}
		for(int j=1;j<=m;j++) if(book[j]) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
