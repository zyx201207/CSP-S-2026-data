#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n;
unsigned long long m;
long long a[N];
unsigned long long d[N];
unsigned long long sum;
long long di[5005][5005];
long long ans,ansi;
long long alld;
long long s1,s2;
bool isd=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    alld=a[2]-a[1];
    for(int i=1;i<=n;i++)
    {
        //cout<<a[i]<<' ';
        if(i>2&&a[i]-a[i-1]!=alld)isd=0;
    }
    //cout<<endl;
    if(isd)
    {
        //cout<<alld<<endl;
        for(int i=1;i<=n;i++)
        {
            s1=i*i*alld;
            s2=i*(i+1)*alld;
            //cout<<s1<<s2<<endl;
            if(s1<=m)ans=2*i;
            else if(s2<=m)ans=2*i+1;
            else break;
        }
        cout<<ans;
        return 0;
    }
    if(n<=500)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]>a[i])d[j]=a[j]-a[i];
                else d[j]=a[i]-a[j];
            }
            sort(d+1,d+n+1);
            sum=0;
            ansi=0;
            for(int j=1;j<=n;j++)
            {
                if(sum+d[j]>m)break;
                sum+=d[j];
                ansi++;
            }
            if(ansi>ans)ans=ansi;
        }
    }
    else if(a[n]<=200&&a[1]>=-200)
    {
        for(int i=a[1];i<=a[n];i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>a[j])d[j]=i-a[j];
                else d[j]=a[j]-i;
            }
            sort(d+1,d+n+1);
            sum=0;
            ansi=0;
            for(int j=1;j<=n;j++)
            {

                if(sum+d[j]>m)break;
                sum+=d[j];
                ansi++;

            }
            if(ansi>ans)ans=ansi;
        }
    }
    else if(n<=5005)
    {
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=n-i+1;j++)
            {
                unsigned long long dis=a[j+i-1]-a[j];
                if(i>3)dis+=di[j+1][i-2];
                di[j][i]=dis;
                //cout<<di[j][i]<<' ';
                if(dis<=m&&ans<i){ans=i;}//cout<<dis<<' '<<m<<' '<<i<<endl;
                //if(dis>m)di[j][i]=-1;

            }//cout<<endl;
        }
    }
    cout<<ans;
    return 0;

}
