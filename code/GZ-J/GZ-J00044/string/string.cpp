//GZ-J00044 贵州市花溪区实验中学 游梓一
#include<bits/stdc++.h>
using namespace std;
int n,a[200000],s,o,now=0,fnow,m;
char b[200001],g;
char p[1000000],h;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		s+=a[i];
		a[i]+=a[i-1];
	}
	o=s/2;
	fnow=n-2;
	cout<<o<<' '<<s<<endl;
	for(int i=0;i<o;i++)
	{
		if(i>a[now])now++;
		if(i<=a[now])g=b[now];
		if(s-i>a[fnow])fnow--;
		if(s-i<=a[fnow])h=b[fnow+1];
		if(g!=h)
			m++;
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
