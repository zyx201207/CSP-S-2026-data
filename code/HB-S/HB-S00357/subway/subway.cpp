#include<bits/stdc++.h>
#define long long ll
using namespace std;
int c,n,m,d,q;
int idx[505],line[505][505];
struct sta
{
    int l=0;
    int step=0;
    int stid;
    int w;
    int a[25],t[25],lid[25];
}st[505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>st[i].w;
    }
    
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int id;
            cin>>id;
            st[id].a[++idx[id]]=i;
            st[id].lid[idx[id]]=j;
            cin>>st[id].t[idx[id]];
            line[i][j]=id;
            st[id].stid=id;
        }
    }
    while(q--)
    {
        int x,y,ans=0,sum=INT_MAX;
        cin>>x>>y;
        ans=ans+st[x].w+st[y].w;
        queue<sta> qsta;
        sta t=st[x];
        qsta.push(t);
        while(!qsta.empty())
        {
            sta r=qsta.front();
            qsta.pop();
            if(r.stid==y)
            {
                sum=min(sum,r.step);
                continue;
            }
            for(int i=1;i<=2;i++)
            {
                if(i==1)
                {
                    for(int j=1;j<=idx[r.stid];j++)
                    {
                        if(st[r.stid].lid[j]>1)
                        {
                            int nx=line[r.a[j]][r.lid[j]-1];
                            sta temp=st[nx];
                            if(r.l!=r.a[j])
                            {
                                temp.step=r.step+r.t[r.l]+r.t[r.a[j]];
                                temp.l=r.a[j];
                            }
                            qsta.push(temp);
                        }
                    }
                }
                else if(i==2)
                {
                    for(int j=1;j<=idx[r.stid];j++)
                    {
                        if(line[r.a[j]][r.lid[j]+1]>0)
                        {
                            int nx=line[r.a[j]][r.lid[j]+1];
                            sta temp=st[nx];
                            if(r.l!=r.a[j])
                            {
                                temp.step=r.step+r.t[r.l]+r.t[r.a[j]];
                                temp.l=r.a[j];
                            }
                            qsta.push(temp);
                        }
                    }
                }  
            }
        }
        cout<<ans+sum<<endl;
    }
    return 0;
}
