#include<bits/stdc++.h>
using namespace std;
int w[255010];//kou dao ting
struct zhan
{
    int c;//zhan de ge shu
   int z[500010],t[500010]; //i tiao xian lu dao da de zhan shu liang, ting dao tai
}a[510];
struct node
{
    vector<int> way,time;//ci zhan bei na xie xian lu jing guo ,shi jian
}vst[255010];
int x,y;
int anstime=0,minans=INT_MAX;
void dfs(int cur)
{
    if(cur==y)
    {
        minans=min(anstime,minans);
        return ;
    }
    for(auto it:vst[cur].way)//jing guo ci zhan de lu xian
    {
        anstime=a[it].t[cur];
        for(int i=1;i<=a[it].c;i++)//zhe xie lu xian suo jing guo de zhan
        {
            anstime+=a[it].t[a[it].z[i]];
            dfs(a[it].z[i]);
            anstime-=a[it].t[a[it].z[i]];
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        a[i].c=k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i].z[j]>>a[i].t[j];
            vst[a[i].z[j]].way.push_back(i);
            //vst[a[i][j]].time.push_back()
        }
    }
    while(q--)
    {
        cin>>x>>y;
        dfs(x);
        cout<<anstime+w[x]+w[y]<<"\n";
    }
    return 0;
}
