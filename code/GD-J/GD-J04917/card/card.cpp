#include<bits/stdc++.h>
using namespace std;
long long n,m,a[888888],tong[888888];
bool vis[888888];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	stack<long long> qu;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]!=1){
			vis[a[i]]=1;
		}
		else{
			while(vis[a[i]]==1){
				int t=qu.top();
				if(t==a[i]){
					vis[a[i]]=0;
				}
				qu.pop();
			}
		}
		qu.push(a[i]);
	}
	while(!qu.empty()){
		int t=qu.top();
		cout<<t;
		tong[t]+=1;
		cout<<tong[t];
		qu.pop();
	}
	for(int i=2;i<n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[i]]!=1){
				vis[a[i]]=1;
			}
			else{
				while(vis[a[i]]==1){
					int t=qu.top();
					if(t==a[i]){
						vis[a[i]]=0;
					}
					qu.pop();
				}
			}
			qu.push(a[i]);
		}
		while(!qu.empty()){
			int t=qu.top();
			cout<<t;
			tong[t]+=1;
			qu.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<"1 ";
	}
	cout<<tong[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
