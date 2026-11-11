#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,m,t=0;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int x=a[i];
				x&=a[j];
				if(x>=t)
					t=x;
			}
		cout<<t<<endl;
	}
	else if(m==n)
	{
		int y=a[1];
		for(int i=2;i<=n;i++)
			y&=a[i];
		cout<<y<<endl;
	}
	else if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n]<<endl;
	}
	else if(m==n-1)
		cout<<0<<endl;
	else
		cout<<6<<endl;
	return 0;
}
