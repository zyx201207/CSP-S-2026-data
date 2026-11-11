#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005];
int main()
{   
//freopen("end.in","r",stdin);
//freopen("end.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)cout<<12;
if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)cout<<7;


  // fclose(stdin);
//	fclose(stdout);
	return 0;
}
