#include<bits/stdc++.h>
using namespace std;
int n,m,a[600009],v[600009],b[600009];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
			cout<<n<<" ";
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}
	else {
		stack<int>q;
		for(int i=1;i<=n;i++){
			memset(v,0,sizeof(v));
			for(int j=i;j<=n;j++){
				if(q.empty()){
					 q.push(a[j]);
					 v[a[j]]=1;
				 }
				 else{
					 if(v[a[j]]==1){
						 while(q.top()!=a[j]){
							 v[q.top()]=0;
							 q.pop();
						 }     
					 } 
					 else{
						 q.push(a[j]);
						 v[a[j]]=1;
					 }
				 }
			}
			while(!q.empty()){
				b[q.top()]++;
				q.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}
	return 0;
}
