#include <iostream>
#include <cstdio>
using namespace std;
struct stu
{
    long long num;
    char s;
}a[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long ls=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].num>>a[i].s;
        ls+=a[i].num;
    }
    long long l1=ls/2;
    long long cnt=0;
    long long i=0,j=n-1;
    while(l1>0&&i<j)
    {
        if(a[i].s==a[j].s)
        {
            if(a[i].num>a[j].num)
            {
                a[i].num-=a[j].num;
                l1-=a[j].num;
                j--;
            }
            else if(a[i].num<a[j].num)
            {
                a[j].num-=a[i].num;
                l1-=a[i].num;
                i++;
            }
            else
            {
                l1-=a[i].num;
                i++;
                j--;
            }
        }
        else
        {
            if(a[i].num>a[j].num)
            {
                cnt+=a[j].num;
                a[i].num-=a[j].num;
                l1-=a[j].num;
                j--;
            }
            else if(a[i].num<a[j].num)
            {
                cnt+=a[i].num;
                a[j].num-=a[i].num;
                l1-=a[i].num;
                i++;
            }
            else
            {
                cnt+=a[i].num;
                l1-=a[i].num;
                i++;
                j--;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
