#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum[300010];
stack<int>t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int shu[300010]={};
		for(int j=i;j<=n;j++){
			if(shu[a[j]]==0){
				t.push(a[j]);
				shu[a[j]]++;
			}else{
				while(t.top()!=a[j]){
					shu[t.top()]--;
					t.pop();
				}
			}
		}while(!t.empty()){
			sum[t.top()]++;
			t.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	/*
10 3
3 1 2 1 3 2 3 1 2 1
	*/
	return 0;
} 
