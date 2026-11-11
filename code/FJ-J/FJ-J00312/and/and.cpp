#include<bits/stdc++.h>
using namespace std;
bool chap(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200000],dp[200000]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,chap);
	for(int j=2;j<=m;j++){
		a[j]=a[j-1]&a[j];
	}
	cout<<a[m];
}