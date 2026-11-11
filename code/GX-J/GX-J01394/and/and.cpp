#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[100005],max=0;
    int cnt=2;
    cin>>n>>m;

        vector <int> v;
        vector <int> p;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
        while(a[i]!=0)
        {
            int c=a[i]%2;
            int h=a[i+1]%2;
            v.push_back(c);
            p.push_back(h);
        }
    }
    for(int i=v.size();i>0;i--)
    {

        if(v[i]==1&&p[i]==1)
            cnt*=2;
    }
    cout<<cnt;
   fclose(stdin);
   fclose(stdout);
    return 0;
}
