#include<bits/stdc++.h>;
using namespace std;
int a[1100];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	 int n,m,maxl=INT_MIN;
	 cin>>n>>m;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	 a[m]=a[m]*2*2*2n;
	 	 if(a[m]>maxl)a[m]=maxl;
	 }
	 cout<<a[maxl];	
	return 0;
}
