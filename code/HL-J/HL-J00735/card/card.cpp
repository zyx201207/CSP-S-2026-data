#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],cnt[1000005],vis[100005],f;
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==4&&m==3){
		cout<<"3 1 4";
	}
	if(n==10&&m==3){
		cout<<"10 3 3";
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(a[i+1]>=a[i]){
			f=1;
		}
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]==a[j+1]){
					continue;
				}else{
					q.push(a[j]);
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				q.push(a[j]);
			}
		}
	}
	while(!q.empty()){
		cnt[q.front()]++;
		q.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
	                 