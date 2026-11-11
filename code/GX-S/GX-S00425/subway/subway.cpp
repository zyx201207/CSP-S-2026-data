#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,t[1000100][21],d,w[1000100],q,x[3][220],c,a[21][1000100],dp[21][1000100];
ll minnode=INT_MAX,ki[1000100];
bool node [1000100][21]={};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        ki[i]=k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j]>>t[a[i][j]][i];
            node[a[i][j]][i]=1;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[1][i]>>x[2][i];
        bool flag=false;
        for(int j=1;j<=n;j++)//at the same line
        {
            if(node[x[1][i]][j]&&node[x[2][i]][j])
            {
                //cout<<"at the same line !\n";
                cout<<w[x[1][i]]+w[x[2][i]]+t[x[1][i]][j]+t[x[2][i]][j]<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            for(int j=1;j<=n;j++)//check two lines in the same station
            {
                for(int k=1;k<=n;k++)
                {
                    if(j==k)
                        break;
                    for(int st1=1;st1<=ki[j];st1++)//station1
                    {
                        for(int st2=1;st2<=ki[k];st2++)//station2
                        {
                            ll time=0;
                            ll notime=0;
                            if(a[j][st1]==a[k][st2]&&(node[x[1][i]][j]||node[x[1][i]][k])&&(node[x[2][i]][j]||node[x[2][i]][k]))
                            {
                                time=w[x[1][i]]+w[x[2][i]]+t[a[j][st1]][j]+t[a[k][st2]][k];
                                if(t[x[1][i]][j]==0)
                                {
                                    time+=t[x[1][i]][k];
                                }
                                else
                                    time+=t[x[1][i]][j];
                                if(t[x[2][i]][j]==0)
                                {
                                    time+=t[x[2][i]][k];
                                }
                                else
                                    time+=t[x[2][i]][j];
                                minnode=min(minnode,time);
                                //cout<<"now line 1:"<<st1<<";line 2:"<<st2<<endl;
                                //cout<<"w[x[1][i]]:"<<w[x[1][i]]<<"w[x[2][i]]"<<w[x[2][i]]<<";t[x[1][i]][j]"<<t[x[1][i]][j]<<";t[x[2][i]][k]:"<<t[x[2][i]][k]<<endl;
                            }
                            else if(a[j][st1]==a[k][st2])
                            {
                                notime+=t[a[j][st1]][j]+t[a[k][st2]][k];
                            }
                        }
                    }
                }
            }
            cout<<minnode<<endl;
        }
    }
    return 0;
}
