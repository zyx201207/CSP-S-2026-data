#include<bits/stdc++.h>
#define int long long
using namespace std;
static int a[100300];
int b[100300];
int n,d;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        int ans=0;
        for (int x=1;x<=n;x++)
        {
            //cout<<"WORK"<<endl;
            memset(b,-1,sizeof(b));
            queue<int>q;
            q.push(x);
            b[x]=0;
            while(!q.empty())
            {
                //cout<<sizeof(q)<<endl;
                int r=q.front();
                //cout<<r<<endl;
                q.pop();
                for (int y=1;(abs(a[r+y]-a[r])<=d)&&r+y<=n;y++)
                {
                    //cout<<"TRYPLUS"<<endl;
                    //cout<<r+y<<" "<<b[r]<<" "<<b[r+y]<<endl;
                    if((b[r+y]>b[r]+1)||b[r+y]==-1)
                    {//cout<<"PLUS"<<endl;
                        b[r+y]=b[r]+1;
                        q.push(r+y);
                    }
                }
                for (int y=1;abs(a[r-y]-a[r])<=d&&r-y>=1;y++)
                {
                    if((b[r-y]>b[r]+1)||b[r-y]==-1)
                    {//cout<<"MINUS"<<endl;
                        b[r-y]=b[r+1];
                        q.push(r-y);
                    }
                }
            }
            //cout<<"BFSOK"<<endl;
            for(int z=1;z<=n;z++)
            {
                if(z==x)continue;
                int mins=b[z],mincnt=0;
                for (int y=1;y<=n;y++)
                {
                    //cout<<z+y<<endl;
                    if(b[z]==b[y]-1)
                    {
                       // mins=b[z+y];
                        mincnt++;
                    }
                    //else if(b[z+y]==mins&&mincnt!=-1)
                        //mincnt++;
                }
                //cout<<mincnt<<endl;
               if (mincnt==2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
