#include<bits/stdc++.h>
using namespace std;
int a[200050]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i+1];
	sort(a+1,a+n+1,greater<int>());
	long long num=a[1];
	for(int i=2;i<=m;i++){
		num=num&a[i];
	}
	cout<<num;
	return 0; 
}
