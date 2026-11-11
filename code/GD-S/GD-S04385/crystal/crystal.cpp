#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m,a[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=1;
	for(int i=2;i<=n;i++){
	
		if(m>=(a[i]-a[i-1])*(i-1)){
		cnt++;
		m-=	(a[i]-a[i-1])*(i-1);
		}
		else break;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
