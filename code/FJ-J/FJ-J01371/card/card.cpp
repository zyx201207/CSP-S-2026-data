#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500012],vis[300012],s[300012];
stack <int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		
		for(int k=i;k<=n;k++){
			if(vis[a[k]]==1){
				while(v.top()!=vis[a[k]]){
					vis[v.top()]=0;
					v.pop();
					
				}
				
			}
			else{
				v.push(a[k]);
				vis[a[k]]=1;
			}
			
			
		}
		for(int k=1;k<=m;k++){
			if(vis[k]==1){
				s[k]++;
			}
			
		}
		while(v.size()){
			
			v.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
