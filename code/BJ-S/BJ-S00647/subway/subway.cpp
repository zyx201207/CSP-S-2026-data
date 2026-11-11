#include<bits/stdc++.h>
using namespace std;
struct xl{
    int b,cnt=0;//b:进出
    int a[25][5];
}x[500005];
int n,m,d,q,ans,fians,len[505],p[500005],cntlen[505];
void find(int l,int r,int xx)
{
    for(int i=1;i<=20;i++)
    {
        if(i==xx)
        {
            continue;
        }
        if(x[l].a[i][1]==0)
        {
            if(ans==0)
            {
                return ;
            }
            fians=min(ans,fians);
            ans=0;
            return ;
        }
        else
        {
            bool flag=false;
            for(int aaa=1;aaa<=20;aaa++)
            {
                if((x[l].a[i][1])==(x[r].a[aaa][1]))
                {
                    ans+=x[l].a[i][2]+x[r].a[aaa][2];
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                for(int j=1;j<=20;j++)
                {
                    int lenk=len[x[l].a[i][1]];
                    for(int aa=1;aa<=lenk;aa++)
                    {
                        int jzq=p[x[l].a[i][1]*cntlen[x[l].a[i][1]-1]+aa];
                        ans+=x[l].a[i][2]+x[jzq].a[i][2];
                        find(jzq,r,i);
                    }
                }
            }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i].b;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        cntlen[i]=cntlen[i-1]+k;
        for(int j=1;j<=k;j++)
        {
            int id;
            cin>>id;
            p[i*cntlen[i-1]+j]=id;
            len[i]=k;
            x[id].cnt++;
            x[id].a[x[id].cnt][1]=i;
            cin>>x[id].a[x[id].cnt][2];
        }
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        fians=1e9;
        ans=0;
        int l1=l,r1=r;
        find(l,r,0);
        cout<<fians+x[l1].b+x[r1].b+x[l1].a[1][2]+x[r1].a[1][2]<<endl;
    }
}