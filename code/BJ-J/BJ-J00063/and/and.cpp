#include<bits/stdc++.h>
using namespace std;
long long f(int a)
{
    long long cnt=0;
    while(a)
    {
        cnt++;
        a/=2;
    }
    return cnt;
}
bool cmp(int a,int b)
{
    return f(a)>f(b);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        a.push_back(y);
    }
    sort(a.begin(),a.end(),cmp);
    int p=a[0];
    for(int i=1;i<m;i++)
    {
        p=p&a[i];
    }
    int ax=-1;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(x==a[j])
            {
                ax=max(ax,x);
            }
        }
    }
    cout<<max(ax,p)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}