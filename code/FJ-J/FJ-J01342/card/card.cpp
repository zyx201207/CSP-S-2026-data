#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int f[200005];
int u[200005];
stack<int>qx;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	u[a[n]]++;
	for(int i=1;i<n;i++){
		for(int j=1+i-1;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=1;
				qx.push(a[j]);
			}
			else{
				while(1){
					if(qx.top()==a[j]){
						break;
					}
					f[qx.top()]=0;
					qx.pop();
				}
			}
		}
		while(!qx.empty()){
			u[qx.top()]++;
			f[qx.top()]=0;
			qx.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<u[i]<<' ';
	return 0;
}
