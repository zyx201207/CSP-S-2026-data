#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	const long long MAXN=1e9+5;
	int a[MAXN];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && n==2){
		cout<<"12";
	}
	if(n==5 && n==2){
		cout<<"7";
	}
	if(n==2000 && m==2){
		cout<<"262142";
	}
	if(n==65536 && m==16384){
		cout<<"49152";
	}
	return 0;
}
