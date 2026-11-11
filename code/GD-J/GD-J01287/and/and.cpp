#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN]={};

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=2147483647;
	for(int i=n-m+1;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
