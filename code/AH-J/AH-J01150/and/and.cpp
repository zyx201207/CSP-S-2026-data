#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,m,ma=-1;
	cin>>n>>m;
	if(m==1){cout<<0;return 0;}
	if(m==2)
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if(ma<(a[i] and a[j])){ma=(a[i]&a[i]);cout<<a[i]<<"  ";}
		
	}
	cout<<ma;
	return 0;
}
//4 2 3 15 12 12
