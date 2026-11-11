#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5000001],cnt[5000001];
stack<int> desk;
int check(int q){
	stack<int> table=desk;
	while(table.top()!=0){
		if(table.top()==q) return 1;
	}	
	return 0;
}	
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	desk.push(0);
	for(int i=1;i<=n;i++){
		for(int j=n-i+1;j<=n;j++){
			if(check(a[j])==1){
				while(desk.top()!=a[j]){
					desk.pop();
				}
			}		
			desk.push(a[j]);
		}	
	}	
	while(desk.top()!=0){
		cnt[desk.top()]++;
		desk.pop();
	}	
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
 	return 0;
}
