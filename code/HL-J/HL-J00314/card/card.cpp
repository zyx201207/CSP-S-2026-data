#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
	}
	return 0;
}
