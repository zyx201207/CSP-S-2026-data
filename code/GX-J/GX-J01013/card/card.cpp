#include <bits/stdc++.h>
using namespace std;
stack<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[5005];
	cin>>n>>m;
	int c[5005],d[5005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]=1;
	}
	int k=1;
	for(int j=1;j<=n;j++){
		for(int i=k;i<=n;i++){
			if(c[a[i]]==1){
				q.push(a[i]);
				c[a[i]]=0;
			}
			else if(c[a[i]]==0){
				if(a[i]==q.top()){
					continue;
				}
				else if(a[i]!=q.top()){
					q.pop();
				}
			}
			
		}
		while(!q.empty()){
			d[q.top()]++;
			q.pop();
		}
		k++;
	}
	for(int l=1;l<=m;k++){
		cout<<d[l]<<" ";
	}
	return 0;
	
}
