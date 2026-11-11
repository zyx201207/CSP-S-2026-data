#include<bits/stdc++.h>
using namespace std;
int n,num,lend;
int a[20005];
string b[20005];
string c,d,e,f;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        lend+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            c=c+b[i];
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=a[i];j>=1;j--)
        {
            d=d+b[i];
        }
    }

    for(int i=0;i<=lend/2-1;i++)
    {
        e=c[i];
        f=d[i];
        if(e!=f)
        {
            num++;
        }
    }
    cout<<num;

	return 0;
}
