//GZ-J00515 邹俊杰 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5010],ml[300010];
int v[300010];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		int j=i;
		stack<int>q;
		while(j<=n){
			if(v[a[j]]==0)q.push(a[j]),v[a[j]]++;
			else{
				do{
				v[q.top()]--;	
				q.pop();	
				}while(q.top()!=a[j]);			
				q.push(a[j]);
				v[a[j]]++;
			}
			j++;
		}
		while(!q.empty()){
			ml[q.top()]++;
			q.pop();
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<ml[i]<<" ";
	}
	return 0;
} 
