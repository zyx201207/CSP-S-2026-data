#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],b[5000005],s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		s=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(j>=2&&a[1]<0)a[j]+=abs(a[1]);
			if(j>=2&&a[1]>0)a[j]-=abs(a[1]);
		}
		a[1]=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<d;k++)
				b[a[j]+d+k]=1;
			s+=b[a[j]];
		}
		cout<<s-1<<endl;
	}
	return 0;
}
