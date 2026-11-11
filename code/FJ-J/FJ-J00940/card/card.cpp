#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int a[5005];
int t[5005];
int ans[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<int> q;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0){
				while(q.top()!=a[j]){
					t[q.top()]=0;
					q.pop();
				}
				q.pop();
			}
			q.push(a[j]);
			t[a[j]]=q.size();	
		}
	while(!q.empty()){
		int k=q.top(); 
		ans[k]++;
		q.pop();
	}
	}	
	for(int i=1;i<=m;i++){
		if(ans[i]!=0) cout<<ans[i]<<" ";
		
	}
	return 0;
}
