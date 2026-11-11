#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],vis[300005],ans[300005],b[500005];
queue<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		q.push(a[i]);
		vis[a[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(vis[a[j]]==0){
				q.push(a[j]);
				vis[a[j]]=1;
			}else{
				q.push(a[j]);
				q.pop(); 
				while(q.front()!=a[j]){
					q.pop();
				}
			}
			q.push(a[j]);
		}
		while(q.size()){
			ans[q.front()]+=1;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
}  
