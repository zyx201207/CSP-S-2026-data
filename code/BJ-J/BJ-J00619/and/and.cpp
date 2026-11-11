#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>m>>n;
    long long a[1000000]={0};
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    while(n--)
    {
        int max1=0,max2=0;
        for(int i=1;i<=m;i++)
        {
            if(a[i]==0) continue;
            for(int j=i+1;j<=m;j++)
            {
                if(a[j]==0) continue;
                if((a[i]&a[j])>(a[max1]&a[max2]))
                {
                    max1=i;
                    max2=j;
                }
            }
        }
        a[max1]=(a[max1]&a[max2]);
        a[max2]=0;
        if(n==1) cout<<a[max1];
    }
    return 0;
}
