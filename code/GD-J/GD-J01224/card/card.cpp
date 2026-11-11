#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],b[N];
vector<int>v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int l=v[i].size();
		if(v[i][l-i]+l<=n){
			b[i]=a[v[i][l-i]+1];
		}
	}
	for(int i=1;i<=m;i++){
		int t=i,l=v[i].;
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	}
}
