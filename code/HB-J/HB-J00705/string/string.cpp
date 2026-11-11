#include<bits/stdc++.h>
using namespace std;
struct num1
{
    long long a;
    char c;
};
num1 num[200499];
int n;
unsigned long long check()
{
    unsigned long long sum=0;
    int i=1,j=n;
    while(i<j)
    {
        if(num[i].a==num[j].a&&num[i].c==num[j].c)
        {
            i++;
            j--;
        }
        else if(num[i].c==num[j].c)
        {
            long long min1;
            min1=min(num[i].a,num[j].a);
            num[i].a-=min1;
            num[j].a-=min1;
            if(num[i].a==0)
            {
                i++;
            }
            if(num[j].a==0)
            {
                j--;
            }
        }
        else
        {
            long long min1;
            min1=min(num[i].a,num[j].a);
            num[i].a-=min1;
            num[j].a-=min1;
            sum+=min1;
            if(num[i].a==0)
            {
                i++;
            }
            if(num[j].a==0)
            {
                j--;
            }
        }
    }
    return sum;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i].a;
        cin>>num[i].c;

    }
    cout<<check();
    return 0;
}
