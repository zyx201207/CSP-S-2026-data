#include<bits/stdc++.h>
using namespace std;
int m,n,a[500001],sum=0,g[300001]={0};
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int b[300001]={0};
		for(int j=i;j<=n;j++){
			sum++;
			if(b[a[j]]==1){
				while(q.top()!=a[j]){
					b[q.top()]=0;
					q.pop();
					sum--;
				}
			}else{
				b[a[j]]=1;
				q.push(a[j]);
			}
		}for(int j=1;j<=m;j++){
			if(b[j]==1){
				g[j]++;
			}
		}
	}for(int i=1;i<=m;i++) cout<<g[i]<<" ";
	
	return 0;
}
