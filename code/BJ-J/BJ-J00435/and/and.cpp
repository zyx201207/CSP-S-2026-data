#include<bits/stdc++.h>
#define int long long
using namespace std;
bool v[200010][70],y[200010];
bool ans[70];
int a[200010];
int n,m;
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int ii=1,aa=a[i];
        while(aa>0)
        {
            v[i][ii]=aa%2;
            aa/=2;
            ii++;
        }
    }
/*
    for(int i=1;i<=n;i++)
    {
        for(int j=16;j>=1;j--)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }*/
    int ttmp=n;
    for(int j=32;j>=1;j--)
    {
        int cnt=0,tmp=0;
        for(int i=1;i<=n;i++)
        {
            if(v[i][j]==1&&y[i]==0)cnt++,tmp=i;
        }
        if(tmp==0)tmp=n;
        //cout<<"jcnt"<<j<<" "<<cnt<<endl;
        if(cnt>=m)
        {
            //cout<<"tmp"<<ttmp<<endl;
            int cc=0;
            for(int i=1;i<=ttmp&&cc<=(ttmp-m);i++)
            {
                if(v[i][j]==0)
                {
                    //cout<<i<<" ";
                    y[i]=1,cc++;
                }
            }
            //cout<<endl;
            ttmp=tmp;
        }

    }

    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(y[i]==0)
        {
            if(ans==-1)ans=a[i];
            else ans&=a[i];
        }
    }
    cout<<ans;
    return 0;
}