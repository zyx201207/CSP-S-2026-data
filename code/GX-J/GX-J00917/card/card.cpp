#include <bits/stdc++.h>
using namespace std;
stack<int> f;
int main(){
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	long long n,m;
	cin>>n>>m;
	int arr[200001]={};
	int mm[200001]={};
	int ks[2001]={};
	for(int i=1;i<=n;i++){
		cin>>ks[i];
	}
	for(int u=n;u>=1;u--){
			for(int i=1;i<=u;i++){
				if(arr[ks[u]]==1){
					while(f.top()!=ks[u]){
						arr[f.top()]=0;
						f.pop();
					}
				}
				arr[ks[u]]=1;
				f.push(ks[u]);
				
			}
			for(int j=1;j<=n;j++){
				if(arr[j]==1){
					mm[j]++;
				}
			}
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<' ';
	}
	return 0;
}
