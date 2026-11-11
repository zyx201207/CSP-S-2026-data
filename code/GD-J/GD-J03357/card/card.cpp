#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int b[M];
vector<int> c[M];
int sum[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int k=a[i];
		if(c[k].empty()){
			for(int j=i;j<=n;j++){
				c[k].push_back(a[j]);
				j=b[a[j]];
			}
		}
		for(int t=0;t<c[k].size();t++){
			sum[c[k][t]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
}
/*
3 1 2 1 3 2 3 1 2 1
*/
