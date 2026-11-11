#include<bits/stdc++.h>
using namespace std;
const int mx=11000;
long long a[mx],n,m,b,d,e=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int j=0;j<n;j++)
    {
        b=a[j];
        while(m>0)
        {
            long long c=-100000;
            for(int j=0;j<n;j++)
                if(abs(a[j]-b)<abs(c-b))c=a[j],d=j;
            a[d]=-100000,m-=abs(c-b),e++;
        }
	}
    if(m<0)cout<<e-1;
    if(m==0)cout<<e;
    return 0;
}

//bu hui
