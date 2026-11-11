#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[100005],sum,key,mins,num,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		cout<<n-(d*2-1);
	}
	return 0;
}
