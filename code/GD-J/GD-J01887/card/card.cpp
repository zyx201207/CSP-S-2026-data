#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[50005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int id[30005]={};
	for(int t=1;t<=n;t++){
		int it[300005]={};
		stack<int> op;
		for(int i=t;i<=n;i++){
			if(it[a[i]]==0){
				op.push(a[i]);
				it[a[i]]+=1;
			}
			else{
				while(op.top()!=a[i]){
					op.pop();
				}
			}
		}
		while(op.size()>0){
			id[op.top()]++;
			op.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<id[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

