#include<bits/stdc++.h>
using namespace std;
int x[2000010];
int n,m;
bool v[2000010];
map<int,long long> p; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)p[i]=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		stack<int> q;
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(v[x[j]]==1){
				while(q.top()!=x[j]){
					v[q.top()]=0;
					q.pop();
				}
				q.pop();
			}
			q.push(x[j]);
			v[x[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(v[j]==1)p[j]++;
		}
		
	} 
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	return 0;
} 
