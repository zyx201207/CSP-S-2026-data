#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int cnt=a[0];
	for(int i=1;i<m;i++){
		cnt=cnt&a[i];
	}
	cout<<cnt;
	return 0;
}
