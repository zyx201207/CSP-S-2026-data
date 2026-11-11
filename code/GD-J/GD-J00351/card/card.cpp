#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[101010]={},c[101001]={};
	queue <int> q;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		b[i]=a;
	}int temp=m;	int k=1,r=1,x[101001]={};
	while(temp--){
	
		for(int i=1;i<=n;i++){
			if(b[i]==q.front()){
				while(!q.empty()){
					q.pop();
				}
			q.push(b[i]);
			}
			else{
				q.push(b[i]);
			}
		}
	
		while(!q.empty()){
			c[k]=q.front();
			k++;
			q.pop();
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				c[j]==i;
				x[r]++;
				r++;
			}
		}
}
for(int i=1;i<=m;i++){
	cout<<x[i]<<" ";
}
	return 0;
} 
