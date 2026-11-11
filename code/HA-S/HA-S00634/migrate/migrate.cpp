#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t,a[1010000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
     cin>>n>>m;
     while(m>0){
     	cin>>c>>t;
     	for(int i=1;i<=c;i++)
     	cin>>a[i];
     	if(a[c]-a[1]<=t)
     	{
     		cout<<0<<endl;
     		return 0;
     	}
     	m--;
     }
}
