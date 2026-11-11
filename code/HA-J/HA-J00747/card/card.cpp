#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ma[300005],am[300005];
stack <int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!ma[a[j]]){
				ma[a[j]]+=1;
				q.push(a[j]);
			}
			else{
				while(q.top()!=a[j]){
					ma[q.top()]--;
					q.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(ma[j]){
				am[j]++;
			}
			ma[j]=0;
		}
		while(!q.empty()){
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<am[i]<<" ";
	}
	return 0;
}
