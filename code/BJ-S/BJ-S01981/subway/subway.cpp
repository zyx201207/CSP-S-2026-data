#include <bits/stdc++.h>
#define test 2
using namespace std;
int c,line,stt,lps,plan;
int tofs[500050];
bool stv[500050];
vector<int>lofs[500050];
int lnst[500050][202];
int lntm[500050][202];
int x,y;
int findstatpos(int st,int stl)
{
    for(int i=1;lnst[i][stl]!=0;i++)
    {
        if(lnst[i][stl]==st)return i;
    }
    return -1;
}
int dfs(int st,int ed,int stl)
{
    if(st==ed)return tofs[ed]+lntm[st][stl];
    stv[st]=1;
    int ans=INT_MAX;
    for(auto &i:lofs[st])
    {
        int pos=findstatpos(st,i);
        if(pos>1&&!stv[lnst[pos-1][i]])ans=min(ans,dfs(lnst[pos-1][i],ed,i)+(i!=stl)*(lntm[lnst[pos-1][i]][stl]+lntm[lnst[pos-1][i]][i]));
        if(!stv[lnst[pos+1][i]]&&lnst[pos+1][i]!=0)ans=min(ans,dfs(lnst[pos+1][i],ed,i)+(i!=stl)*(lntm[lnst[pos+1][i]][stl]+lntm[lnst[pos+1][i]][i]));
    }
    stv[st]=0;
    return ans;
}
int main()
{
    #ifdef test
     freopen("subway.in","r",stdin);
     freopen("subway.out","w",stdout);
    #endif // test
    cin>>c>>line>>stt>>lps>>plan;
    for(int i=1;i<=stt;i++)
        cin>>tofs[i];
    for(int i=1;i<=line;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>lnst[j][i]>>lntm[j][i];
            lofs[lnst[j][i]].push_back(i);
        }
    }
    for(int i=1;i<=plan;i++)
    {
        cin>>x>>y;
        int ans=INT_MAX;
        for(auto &i:lofs[x])
            ans=min(ans,dfs(x,y,i)+tofs[x]+lntm[x][i]);
        cout<<ans<<endl;
    }
    return 0;
}
