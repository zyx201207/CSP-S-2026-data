#include <bits/stdc++.h>
using namespace std;
int n,m,a[25],sum,maxn=-1;
string s1[25];
int main()
{
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        string s;
        while(a[i]>0)
        {
            s+=(char)((a[i]%2)+'0');
            a[i]/=2;
        }
        s1[i]=s;

    }
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum=0;
            for(int m=0;m<max(s1[i].size(),s1[j].size());m++)
            {

                if(s1[i][m]==s1[j][m])
                {

                    sum+=pow(2,i);
                }
            }
            maxn=max(maxn,sum);
        }
    }
    cout<<sum/2-4;
    return 0;
}
