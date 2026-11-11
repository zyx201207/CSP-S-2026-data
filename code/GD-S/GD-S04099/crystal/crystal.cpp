/*
ÄÜÁ¿Ë®¾§£¨crystal£©
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;x+i<=m;i++){
 		x+=i;
 		ans++;
	 }
	 ans=min(n,ans);
	 cout<<ans;
	return 0;
}
