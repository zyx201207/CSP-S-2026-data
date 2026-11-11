#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long,char> a[200005];
long long sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    int l=1,r=n;
    while(l!=r)
    {
        if(a[l].first>a[r].first)
        {
            a[l].first-=a[r].first;
            if(a[l].second!=a[r].second)sum+=a[r].first;
            r--;
        }
        else if(a[l].first<a[r].first)
        {
            a[r].first-=a[l].first;
            if(a[l].second!=a[r].second)sum+=a[l].first;
            l++;
        }
        else
        {
            if(a[l].second!=a[r].second)sum+=a[l].first;
            r--;
            if(l==r)break;
            l++;
        }
    }
    cout<<sum;
    return 0;
}
