#include<iostream>
#include<climits>
using namespace std;
int n,m;
long long a[200001],choose[200001],ans=0;
//int c[200001];
//void init(int x){for(int i=1;i<=m;i++)c[i]=(x>>(i-1))&1;}
bool checkC()
{
    for(int i=1;i<=20;i++)if(a[i]>=4)return false;
    return true;
}
void dfs(int pos,int ind)
{
    if(pos>m)
    {
        //cout<<"choose:";
        //for(int i=1;i<=m;i++)cout<<choose[i]<<" ";
        long long res=choose[1];
        //cout<<"nowres:"<<res<<" ";
        for(int i=2;i<=m;i++)
        {
            res&=choose[i];
            //cout<<res<<" ";
        }
        //cout<<"\n";
        ans=max(ans,res);
        return;
    }
    //cout<<"ind:"<<ind<<"\n";
    for(int i=ind+1;i<=n;i++)
    {
        choose[pos]=a[i];
        dfs(pos+1,i);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    //if(checkC())
    dfs(1,0);
    cout<<ans;
    return 0;
}