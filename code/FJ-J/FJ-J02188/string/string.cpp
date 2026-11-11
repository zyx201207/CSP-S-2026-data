#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
char c[100005];
long long L;
int ans;
char b[1000005];
int qrt;
int l,r;
int samf=1;
bool x_x_xxx[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	     for(int j=1;j<=n;j++)
	     {
	     	L=j*a[i]+1;
		 }
		 for(int q=samf;q<=samf+c[i];q++)
		b[q]=c[i];
		samf+=a[i];
	}
	l=L;
	r=1;
    while(1)
    {
    	if(l==r||(x_x_xxx[l]==true&&x_x_xxx[r]==true))
    	break;
    	else
    	{
    	if(b[l]!=b[r]&&x_x_xxx[l]!=true&&x_x_xxx[r]!=true)
    	ans++,x_x_xxx[l]=true,x_x_xxx[r]=true;
    	else
    	x_x_xxx[l]=true,x_x_xxx[r]=true;}
    	l--;
    	r++;
	}
	cout<<ans;
	return 0;
}
//f**k CCF