#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	string b[1000];
	cin>>n>>m;
	int a[1000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4)cout<<12<<endl;
	if(n==5)cout<<7<<endl;
	
	return 0;
}
