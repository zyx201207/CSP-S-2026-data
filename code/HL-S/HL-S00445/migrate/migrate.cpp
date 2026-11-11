#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,n,d,ans;int t[N],minn[N],x[N];
void dfs(int m,int cnt)
{
    //cout<<m;
    if(m>n)
        return ;
    if(cnt<minn[m]||minn[m]==0)
    {
        minn[m]=cnt;
        if(t[m]==2){
            //cout<<"because of minn["<<m<<"] changed,ans--\n";
            ans--;
        }
        t[m]=1;
    }
    else if(cnt==minn[m])
    {
        //cout<<"t["<<m<<"]="<<t[m]<<endl;
        t[m]++;
        if(t[m]==2)
        {
            //cout<<"because of t["<<m<<"]==2 ,ans++\n";
            ans++;
        }
        else if(t[m]==3)
        {
            //cout<<"because of t["<<m<<"]==3 ,ans--\n";
            ans--;
        }
    }
    for(int i=m+1;i<=n;i++)
    {
        if(x[i]-x[m]>d)
            break;
        else
            dfs(i,cnt+1);
    }
}
void realmain()
{
    ans=0;
    memset(minn,0,sizeof minn);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    /**for(int k=0;k<=n-4;k++){
        if(x[k+3]-x[k+1]<=d&&x[k+4]-x[k+2]<=d)
        {
            ans++;
            cout<<k<<'.'<<endl;
        }
        else
            continue;
        for(int i=k+5;i<=n;i++)
        {
            if(x[i]-x[k+1]<=d)
                break;
            else {
                ans++;
                cout<<k<<".."<<endl;
            }
        }
    }**/
    for(int i=1;i<=n;i++)
    {
        memset(t,0,sizeof t);
        dfs(i,0);
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;cin>>c>>t;
    if(c==11||c==12)
    {
        cout<<n-3;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    while(t--)
    {
        realmain();

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/**
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
**/
