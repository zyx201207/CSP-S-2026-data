#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
bool b[500050];
int js[500050];
stack<int> q;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		memset(b,0,sizeof(b));
		for(int j=i; j<=n; j++) {
			if(b[a[j]]==0) q.push(a[j]),b[a[j]]=1;
			else {
				while(!q.empty()) {
					if(q.top()==a[j]) 
						break;
					else b[q.top()]=0,q.pop();
				}
			}
		}
		while(!q.empty()) {
			js[q.top()]++;
			q.pop();
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<js[i]<<" ";
	}
	return 0;
}
