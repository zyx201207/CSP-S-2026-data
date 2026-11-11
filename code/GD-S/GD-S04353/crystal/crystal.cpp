#include<bits/stdc++.h>
using namespace std;
int n,c;
long long m,am[500005];
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],am[i]=am[i-1]+a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		for(int j=i-1;j>=1;j--){
			if((am[i]-am[j]+m)%a[i]==0)c=max(c,i-j);
		}
	}cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
