#include<bits/stdc++.h>
using namespace std;
stack<int> Q;
int a[500009];
int T[300009];
int ans[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(T[a[j]]==0){
				Q.push(a[j]);
				T[a[j]]++;
			}else{
				while(Q.top()!=a[j]){
					T[Q.top()]--;
					Q.pop();
				}
			}
		}
		while(!Q.empty()){
			T[Q.top()]--;
			ans[Q.top()]++;
			Q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
