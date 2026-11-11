#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	int o=0;
	for(int i=1;i<=m;i++){
		int k,l;
		cin>>k>>l;
		int a[k+2];
		for(int j=1;j<=k;j++)cin>>a[j];
		sort(a+1,a+n+1);
	if(a[1]>0&&i==1)o=1;
	cout<<o<<endl;
	o++;
		}
	
return 0;
}
