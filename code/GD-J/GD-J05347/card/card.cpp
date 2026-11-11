#include<bits/stdc++.h>
using namespace std;
int const N=5e5+7,M=3e5+7;
int n,m;
int a[N],b[N],t[N],ans[M];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	bool oj=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			oj=0;
			break;
		}
	}
	if(!oj){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(t[a[j]]){
					while(q.top()!=a[j]){
						t[q.top()]=0;
						q.pop();
					}
				}
				else{
					q.push(a[j]);
					t[a[j]]=1;
				}
			}
			while(!q.empty()){
				ans[q.top()]++;
				t[q.top()]=0;
				q.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]) ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
