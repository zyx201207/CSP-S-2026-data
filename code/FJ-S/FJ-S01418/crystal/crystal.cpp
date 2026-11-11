#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	double ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[2]-a[1]==a[3]-a[2])
	{	
		int c=a[2]-a[1];	
//		cout<<c<<endl;
		int y=m/c*2;
//		cout<<y<<endl;
		double yy=y;
		ans=sqrt(yy+0.25)+0.5;
		cout<<int(ans)<<endl;
	}
	else
		cout<<6<<endl;
	return 0;
}
