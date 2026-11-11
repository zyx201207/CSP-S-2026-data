#include <bits/stdc++.h>
using namespace std;
struct sr
{
    int num;
    char zm;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    sr a[n+5];
    stack<sr>b;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].num>>a[i].zm;
        b.push(a[i]);
    }
    long long int cnt=0;
    int i=0;
    while(!b.empty())
    {
        if(b.top().zm==a[i].zm)
        {
            if(a[i].num>b.top().num)
            {
                a[i].num-=b.top().num;
                b.pop();
            }
            else
            {
                sr n;
                n=b.top();
                n.num-=a[i].num;
                b.pop();
                b.push(n);
                i++;
            }
        }
        else
        {
            if(a[i].num>b.top().num)
            {
                a[i].num-=b.top().num;
                cnt+=b.top().num;
                b.pop();
            }
            else
            {
                sr n;
                n=b.top();
                n.num-=a[i].num;
                cnt+=a[i].num;
                b.pop();
                b.push(n);
                i++;
            }
        }
    }
    cout<<cnt/2;
    return 0;
}
