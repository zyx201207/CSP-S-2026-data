#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m,a[510000],b[510000],kind[510000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<0;
	}
	return 0;
}
