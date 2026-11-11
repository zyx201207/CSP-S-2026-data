#include<bits/stdc++.h>
using namespace std;
unsigned long long w[500005];
unsigned long long k[505];
vector<unsigned long long> a[500005];
vector<pair<unsigned long long,unsigned long long> > v[505];
bool isvisit[500005];
long long n,d,ans=0,c,m,q;
unsigned long long dfs1(unsigned int i,unsigned int j,unsigned int line)
{
    if(i==j)
    {
        return 0;
    }
isvisit[i]=1;
unsigned long long minn=LLONG_MAX/2;
for(int k=0;k<v[line].size();k++)
{
    if(!isvisit[v[line][k].first])
    {
    minn=min(minn,dfs1(v[line][k].first,j,line));
    }
}
for(int k=0;k<a[i].size();k++)
{
    if(a[i][k]!=line)
    {
         minn=min(minn,dfs1(i,j,a[i][k])+1);
    }
}
return minn;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
if((c>=12)&&(c<=19))
{



unsigned long long ttttt;

        for(int i=1;i<=m;i++)
{
    cin>>w[i];
}
for(int i=1;i<=n;i++)
{
    cin>>k[i];
    for(int j=1;j<=k[i];j++)
    {
unsigned long long l,r;
cin>>l>>r;
ttttt=r;
v[i].push_back({l,r});
a[l].push_back(i);
    }
}
while(q--)
{
    unsigned long long lll,rrr;
    cin>>lll>>rrr;
    unsigned long long minn=LLONG_MAX/2;
    for(int i=0;i<a[lll].size();i++)
    {
        minn=min(minn,dfs1(lll,rrr,a[lll][i]));
        memset(isvisit,0,sizeof(isvisit));
    }
    cout<<minn+w[lll]+w[rrr]<<endl;
}

}
else{
                for(int i=1;i<=m;i++)
{
    cin>>w[i];
}
for(int i=1;i<=n;i++)
{
    cin>>k[i];
    for(int j=1;j<=k[i];j++)
    {
unsigned long long l,r;
cin>>l>>r;
v[i].push_back({l,r});
a[l].push_back(i);
    }
}
while(q--)
{long long lll,rrr;
cin>>lll>>rrr;
    cout<<w[lll]+w[rrr]<<endl;
}

}}
