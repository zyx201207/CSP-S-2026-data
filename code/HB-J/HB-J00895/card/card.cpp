#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define fori(n) for(int i=1;i<=n;i++)
#define forj(n,j) for(int j=1;j<=n;j++)
#define forlr(l,r) for(int i=l;i<=r;i++)
#define forlrj(l,r,j) for(int j=l;j<=r;j++)
#define ford(i) for(int i=n;i>=1;i--)
#define fordj(n,j) for(int j=n;j>=1;j--)
#define forlrd(r,l) for(int i=r;i>=l;i--)
#define forlrdj(r,l,j) for(int j=r;j>=l;j--)
//Track||Treat!

bool isPrime(int n)
{
    if(n==0||n==1)return 0;
    forlr(2,sqrt(n))
    {
        if(n%i==0)return 0;
    }
    return 1;
}

int a,b[300005],t[300005],c[500005];
int n,m;
int f[300005];


int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    fori(n)
    {
		scanf("%d",&a);
		f[a]=i;
	}
    
    fori(m)printf("%d ",f[i]);
}
