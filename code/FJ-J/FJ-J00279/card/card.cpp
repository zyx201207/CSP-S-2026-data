#include<bits/stdc++.h>
using namespace std;
stack<int>p;
int n,m,a[100005];
bool find(int n1,int j,int k){
	for(int i=k;i<=j;i++){
		if(a[i]==n1){
			a[i]=-1;
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[100005]={};
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(find(a[i],i-1,j))p.push(a[i]);
			else {
				while(p.top()!=a[i]){
					p.pop();
				}
			}
		}
		while(!p.empty()){
			b[p.top()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

