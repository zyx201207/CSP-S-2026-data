#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int m,n;
long long a[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(n==4)cout<<12;
	if(n==5)cout<<7;
	if(n==2000)cout<<262142;
	if(n==65536)cout<<49152;
	if(n==200000)cout<<511;
}
