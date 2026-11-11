#include <bits/stdc++.h>
using namespace std;
int n,a,f,num;
string c[20000],d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a>>c[i];
	for(int j=1;j<=a;j++)
	{
		d+=c[i];
        f++;
	}
}
for(int i=1;i<=f;i++)
{

    if(d[i-1]!=d[f-i])
    {
        d[i-1]=d[f-i];
        num++;
	}

}
cout<<num;
return 0;
}
