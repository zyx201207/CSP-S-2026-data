#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,greater<int>());
	int mx=a[1];
	for(int i=2;i<=m;i++){
		mx=mx and a[i];
	}cout<<mx;
}
