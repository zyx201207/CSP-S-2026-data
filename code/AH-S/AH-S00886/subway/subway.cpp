#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
vector<int>w(m);
vector<int>k(n);
int at[500][500000][2];
vector<int>x(q);
vector<int>y(q);
vector<vector<int>>be(m,vector<int>(d));
vector<int>done(m);
vector<vector<int>>road(m+1,vector<int>(m+1));
vector<vector<int>>line(m+1,vector<int>(m+1));
vector<int>donel(m);
vector<int>ti(q,0);
int t=0;
bool belong(int a,int b)
{
    for(int i=0;i<k[b];i++)
    {
        if(a==at[b][i][1]){
            return 1;
        }
    }
    return false;
}
bool beldo(int a)
{
    for(int i=0;i<m;i++)
    {
        if(a==done[i])
        {
            return true;
        }
    }
    return false;
}
bool beldol(int a)
{
    for(int i=0;i<m;i++)
    {
        if(a==donel[i])
        {
            return true;
        }
    }
    return false;
}
int pos(int x,int y)
{
    for(int i=0;i<k[y];i++)
    {
        if(x==at[y][i][1])
        {
            return i;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c;cin>>n;cin>>m;cin>>d;cin>>q;
    for(int i=0;i<m;i++)
    {

        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            cin>>at[i][j][1];cin>>at[i][j][2];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x[i];cin>>y[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(belong(i,j)==1)
            {
                be[i][j]=j;
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<d;j++){
            for(int o=0;o<k[be[x[i]][j]];o++){
            if(beldo(be[done[j]][j])==0){
            done.push_back(at[be[x[i]][j]][o][1]);
            road[0][t]=at[be[x[i]][j]][o][1];
            t++;
            }
                }
        }
        int p=0;
        int r=1;
        int u;
        while(t<m){
                u=t;
        for(int j=0;j<d;j++){
                for(int e=p;e<=t+1;e++)
                {
                    for(int o=0;o<k[be[done[j]][e]];o++){
                    if(beldo(be[done[j]][e])==0)
                    {
                        done.push_back(at[be[done[j]][e]][o][1]);
                        if(road[r][j]==0){
                        road[r][j]=at[be[x[i]][j]][o][1];
                        }
                        else{
                                for(int o=0;o<r;r++){
                            road[r][t]=road[r][j];
                            t++;
                                }
                            road[r][t]=at[be[x[i]][j]][o][1];
                        }
                    }
                    }
                }

        }
        r++;
        p=u;
        }
        for(int o=0;o<d;o++){
                for(int e=0;e<k[be[x[i]][o]];e++){
            if(beldol(be[donel[o]][e])==0){
            donel.push_back(be[x[i]][o]);
            road[0][t]=be[x[i]][o];
            t++;
            }
        }
        }
        p=0;
        r=1;
        u=0;
        while(t<m){
                u=t;
        for(int j=0;j<d;j++){
                for(int e=p;e<=t+1;e++)
                {
                    for(int o=0;o<k[be[done[j]][e]];o++)
                    if(beldo(be[done[j]][e])==0)
                    {
                        done.push_back(be[done[j]][e]);
                        if(road[r][j]==0){
                        road[r][j]=be[x[i]][j];
                        }
                        else{
                            road[r][t]=road[r][j];
                            t++;
                            road[r][t]=be[x[i]][j];
                        }
                    }
                }

        }
        r++;
        p=u;
        }
        for(int k=0;(k<m)&&(road[0][k]!=0);k++)
        {
            int v=x[i];
            ti[k]=w[x[i]]+w[y[i]];
            for(int j=1;j<m;j++)
            {
                if(road[k][j]==y[k]){
                    ti[k]+=at[line[k][j-1]][pos(v,line[k][j-1])][2];
                    j=m;
                }
                else if(road[k][j]!=0){
                ti[k]+=at[line[k][j]][pos(road[k][j],line[k][j])][2]+at[line[k][j-1]][pos(v,line[k][j-1])][2];
                }
                else if(road[k][j]==0){
                    ti[k]=0;
                }

            }
        }
        long long mi=10000000;
        for(int k=0;k<m;k++)
        {
            if((ti[k]!=0)&&ti[k]<mi)
            {
                mi=ti[k];
                ti[k]=0;
            }
        }
        cout<<mi<<endl;

    }


return 0;

}
