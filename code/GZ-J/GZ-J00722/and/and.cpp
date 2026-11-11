//GZ-J00722 都匀市第十中学 陈光皓轩 
#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=0,a[200005],ct=0;
int main(){
	freopen("and1.in","r",stdin);
	freopen("xx.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-m+1;i++){
		ct=a[i];
		for(int j=1;j<m;j++){
			ct&=a[i+j];
		}
		mx=max(mx,ct);
	}
	cout<<ct;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

