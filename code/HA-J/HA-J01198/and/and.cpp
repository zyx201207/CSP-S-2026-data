#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N],n,m,maxn;
int dev(int x){
	int maxm=INT_MIN;
	for(int i=x;i<=n;i++){
		for(int j=1;j<=m;j++)
		maxm=max((a[i]&a[i+1]),maxm);
	}
	return maxm;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dev(i));
	}
	cout<<maxn;
	return 0;
}
