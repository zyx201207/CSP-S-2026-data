//GZ-J00468 遵义市第十二中学 周泽恩 
#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[1000005];
int as[1000005];
int vis[1000005]={0};
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int zz=0;
	for(int i=1;i<=n;i++){
		
		if(i+zz<=n){
			if(vis[a[i+zz]]==0){
				while(!q.empty()){
					as[q.front()]++;
					q.pop();
					//if(q.front()==a[i+zz])break;
				}
				q.push(a[i+zz]);
				vis[a[i+zz]]=1;
			}
			else{
				q.push(a[i+zz]);
				vis[a[i+zz]]=1;
			}
		}
		zz++;
		
	}
	for(int i=1;i<=m;i++)cout<<as[i]<<' ';
	fclose(stdin);
	fclose(stdout);
} 
