#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll n,d,maxStep;
ll a[2000004];
bool flag=true;
int sum=0;
int ans=0;
void dfs(int x,int y,int num)
{
    if(num==maxStep)
    {
        if(y==x)
        {
            sum++;
        }
        return;
    }
    for(int i=1;i<=d;i++)
    {
        dfs(x,y-i,num+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(a[n]-a[1]<=d)
        {
            cout<<0<<'\n';
            continue;
        }
        int step=1;
        ans=0,sum=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]-a[i-1]>d)
            {
                cout<<"0\n";
                flag=false;
                break;
            }
            int k=i;
            while(a[i]-a[k]<d)
                i++;
            //i--;
            step++;        
        }
        if(flag==false)continue;
        maxStep=step;
        dfs(1,n,0);
        if(sum==2)
            ans++;
        cout<<ans<<'\n';
    }
    return 0;
}