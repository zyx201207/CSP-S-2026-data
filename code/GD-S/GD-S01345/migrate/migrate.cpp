#include<bits/stdc++.h>
using namespace std;

const int M=2e6+1000;
int a[M],c,t,n,d;

void sss()
{
	int x=a[2]-a[1];
	if(d<3*x&&d>=2*x)
	{
		cout<<n-2<<'\n';
	}
	else cout<<"0"<<'\n';
}


int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
			sss();
	}
	

	return 0;
	
} 
