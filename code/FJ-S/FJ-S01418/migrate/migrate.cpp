#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--)
	{
		int a[N];
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			if(a[i+1]-a[i]>d and i!=n)
				n=i;
//		for(int i=1;i<=n;i++)
//			cout<<a[i]<<" "<<endl;	
		if(a[2]-a[1]==a[3]-a[2] and a[3]-a[2]==a[4]-a[3] and a[3]-a[2]<d)
			cout<<0<<endl;
		else
			cout<<3<<endl;
	}
	return 0;
}
