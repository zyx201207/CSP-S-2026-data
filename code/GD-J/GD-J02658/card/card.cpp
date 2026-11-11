#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int v[300010];
stack<int> q;
int b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(v[a[j]]!=0){
					while(q.top()!=a[j]){
						v[q.top()]=0;
						q.pop();
					}
					v[q.top()]=0;
					q.pop();
				}
				v[a[j]]=1;
				q.push(a[j]);
			}
			for(int j=1;j<=m;j++){
				b[j]+=v[j];
				v[j]=0;
			}
			while(!q.empty()) q.pop();
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			b[a[i]]=max(b[a[i]],i);
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}
	
	return 0;
} 
