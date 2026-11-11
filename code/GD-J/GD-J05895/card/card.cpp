#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],c[300009];
stack<int>p;
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		vector<bool>b(m+1,0);
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
			p.push(a[j]);
			b[a[j]]=1;
			}
			else{
				while(p.top()!=a[j]){
					p.pop();
				}
			}
			
		}
		while(!p.empty()){
		c[p.top()]++;
		p.pop();
		cout<<"1";
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",c[i]);
	return 0;
} 
