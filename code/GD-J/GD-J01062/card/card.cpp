#include<bits/stdc++.h>
using namespace std;
int a[1000086];
int b[9999999];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	int c[m+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> q;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				b[a[j]]--;
				while(q.top()!=a[j]){
					q.pop();
				}
				q.pop();
			}
			q.push(a[j]);
			b[a[j]]++;
		}
		while(!q.empty()){
			int p=q.top();
			if(p<=m){
				c[p]++;
			}
				q.pop();
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
