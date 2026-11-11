#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    long long a[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int maxn=1;
    if(m==0)
    {
        cout<<1;
        return 0;
    }
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        int num=1;
        for(int j=i-1;j>=0;j--)
        {
            long long c=m;
            //cout<<"i"<<i<<endl;

            long long f=a[i]-a[j];
            if(c>=f)
            {
                c-=f;
                num++;
                //cout<<"t"<<endl;
                //cout<<"c"<<c<<endl;
            }
            else
            {
                j=-1;
                maxn=max(num,maxn);
            }
        }
    }
    cout<<maxn;
}
