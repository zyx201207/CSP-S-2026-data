#include<bits/stdc++.h>
using namespace std;
const unsigned long long F = 3; 
int n,m;
int a[500050],ji[300030];
bool u[300030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=m;i++){
		queue<int> q;
		for(int z = 1;z<=300030;z++){
			u[z] = 0;
		}
		for(int j = i;j<=n;j++){
			if(!u[a[j]]){
				q.push(a[j]);
			}else{
				int flag = 0,s = q.size();
				while(s--&&!q.empty()){
					int x = q.front();
					if(x==a[j]){
						flag = 1;
					}
					if(!flag){
						q.pop();
						q.push(x);
					}else{
						q.pop();
					}
				}
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			int x = q.front();
			q.pop();
			ji[x]++;
		}
	}
	for(int i = 1;i<=300000;i++){
		if(ji[i]!=0){
			cout<<ji[i]<<' ';
		}
	}
	return 0;
}
