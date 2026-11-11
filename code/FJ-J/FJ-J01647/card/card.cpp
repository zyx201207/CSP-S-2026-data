#include<bits/stdc++.h>
using namespace std;

int n,m,a[100007],f[100007],z[100007];
stack<int> q; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[j]=false;
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(q.top()!=a[j]) {
					f[q.top()]=false;
					q.pop();
				}	
				q.pop();
			}
			f[a[j]]=true;
			q.push(a[j]);
			
		}
		
		while(!q.empty()){
			z[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<z[i]<<" ";
	cout<<endl;
	return 0;
}

