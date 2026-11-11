#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmd);
	cout<<a[m-1];
	return 0;
}
