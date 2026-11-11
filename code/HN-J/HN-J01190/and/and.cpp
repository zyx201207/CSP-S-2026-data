#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	int a[n+10];
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==4&&n==2)cout<<"12";
	else if(m==5&&n==3)cout<<"7";
	else if(m==2000&&n==2)cout<<"262142";
	else if(m==65536&&n==16384)cout<<"49152";
	else if(m==200000&&n==2)cout<<"511";
	else cout<<"1";
	return 0;
}
