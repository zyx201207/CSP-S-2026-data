#include<bits/stdc++.h>
using namespace std;
const int mn=6E7+50,mm=5E5+50;
int head[mm],lend[mn],leto[mn],lenx[mn],l;
int a[mm];
int ans[mm],dl;
bool v[1000][1000];
struct DOB
{
    int X;
    int to;
}d[mn];
void dup(int k)
{
    if (k==1)
        return;
    int f=k/2;
    if (d[f].X>d[k].X)
    {
        swap(d[f],d[k]);
        dup(f);
    }
}
void ddow(int k)
{
    int s1=k*2;
    int s2=k*2+1;
    if (s1>dl)
        return;
    if (s2<=dl && d[s2].X<d[s1].X)
    {
        if (d[s2].X<d[k].X)
        {
            swap(d[s2],d[k]);
            ddow(s2);
            return;
        }
    }
    if (d[s1].X<d[k].X)
    {
        swap(d[s1],d[k]);
        ddow(s1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,D,p;
    cin>>c>>n>>m>>D>>p;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        int t[mm],b[mm];
        int tn;
        cin>>tn;
        for (int j=1;j<=tn;j++)
        {
            cin>>b[j]>>t[j];
            for (int k=j-1;k>0;k--)
            {
                int x=b[k],y=b[j];
                lend[++l]=t[j]+t[k];
                leto[l]=x;
                lenx[l]=head[y];
                head[y]=l;
                lend[++l]=t[j]+t[k];
                leto[l]=y;
                lenx[l]=head[x];
                head[x]=l;
                v[x][y]=1;
                v[y][x]=1;
            }
        }
    }
   // for (int i=1;i<=m;i++)
   // {
    //    int j=head[i];
    //   while (j!=0)
    //    {
    //        cout<<i<<"->"<<leto[j]<<" "<<lend[j]<<"\n";
    //        j=lenx[j];
    //    }
    //}
    while (p--)
    {
        dl=0;
        int st,ed;
        cin>>st>>ed;
        for (int i=1;i<=m;i++)
        {
            ans[i]=-1;
        }
        ans[st]=0;
        int k=st;
        while (k!=ed)
        {
            for (int i=head[k];i!=0;i=lenx[i])
            {
                if (ans[leto[i]]=-1)
                {
                    d[++dl].X=ans[k]+lend[i];
                    d[dl].to=leto[i];
                    dup(dl);
                }
            }
            while (ans[d[1].to]!=-1)
            {
                swap(d[1],d[dl]);
                dl--;
                ddow(1);
            }
            int kn=d[1].to;
            ans[kn]=d[1].X;
            if (v[k][kn]==0)
            {
                lend[++l]=ans[kn];
                leto[l]=kn;
                lenx[l]=head[k];
                head[k]=l;
                v[k][kn]=1;
                lend[++l]=ans[k];
                leto[l]=k;
                lenx[l]=head[kn];
                head[kn]=l;
                v[kn][k]=1;
            }
            k=kn;
        }
        cout<<ans[ed]+a[st]+a[ed]<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
 4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
