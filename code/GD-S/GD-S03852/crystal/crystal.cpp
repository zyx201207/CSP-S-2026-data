#include<iostream>
#include<cstdio>
using namespace std;
int a[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	cout<<n-a[1];
	freopen(stdin);
	freopen(stdout);
	return 0;
}
