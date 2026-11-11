//GZ-S00443 陈光皓轩 都匀市第十中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],ct[10005],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(m--){
		sort(a+1,a+n+1);
		a[1]++;
	}
	for(int i=1;i<=n;i++)ct[a[i]]++;
	sort(ct+1,ct+n+1);
	cout<<ct[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Oct31==Dec25?
