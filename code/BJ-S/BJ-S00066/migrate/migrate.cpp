#include<bits/stdc++.h>
using namespace std;
int n,a[2000001],d;
vector<int> lens;
int dfs(int start,int ends,int d,int place)
{

    int minm2=1000001;
    if(start==ends)
        return 1;
    for(int i=start+1;i<=ends;i++)
    {
        if(a[i]-start<=d)
        {
            if(place==1)
            {
                int k=dfs(a[i],ends,d,place+1)+1;
                lens.push_back(k);
            }
            else
            {
                minm2=min(minm2,dfs(a[i],ends,d,place+1)+1);
            }
        }
    }
    if(place==1)
    {
        int cnt=0;
        sort(lens.begin(),lens.end());
        int minm=lens[1];
        for(int i=1;i<lens.size();i++)
        {
            if(lens[i]==minm)
                cnt++;
        }
        return cnt;
    }
    return minm2;
}
void del()
{
    for(int i=1;i<=lens.size();i++)
        lens.pop_back();
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int sum=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                del();
                if(dfs(a[i],a[j],d,1)==2)
                {
                    sum++;
                }
            }
        cout<<sum<<endl;
    }
    return 0;
}
