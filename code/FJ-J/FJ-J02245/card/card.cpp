#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],j,b[500100]={},k,c[500100]={};
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=n;o++){
		j=n-o+1;
		memset(b,0,sizeof(b));
		k=o;
		while(k<=n){
			if(b[a[k]]==1){
				while(q.top()!=a[k]){
				    b[q.top()]=0;
					q.pop();
				}
				q.pop();
				b[a[k]]=0;	
				}
			q.push(a[k]);
			b[a[k]]++;
			k++;	
			}
			while(!q.empty()){
			c[q.top()]++;
			q.pop();
		}
		}
	for(int p=1;p<=m;p++){
			cout<<c[p]<<' ';
		}
	return 0;
}
