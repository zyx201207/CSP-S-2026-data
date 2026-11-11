#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c=0,n=0,m=0,d=0,q=0;
    cin>>c>>n>>m>>d>>q;
    vector<long long> out(m+2,0);
    vector<vector<long long> > to_line(m+2);
    vector<vector<long long> > line_to(n+2);
    vector<vector<long long> > lt(n+2);
    for(long long i=1;i<=m;i++)
    {
        cin>>out[i];
    }
    for(long long i=1;i<=n;i++)
    {
        long long k=0;
        cin>>k;
        for(long long x=1;x<=k;x++)
        {
            long long a=0,t=0;
            cin>>a>>t;
            to_line[a].push_back(i);
            line_to[i].push_back(a);
            lt[i].push_back(t);
        }
    }
    for(long long i=1;i<=q;i++)
    {
        long long start=0,last=0;
        cin>>start>>last;
        vector<long long> dp(m+2,999999999);
        queue<pair<long long,long long> > now;
        long long ans=0;
        ans=ans+out[start]+out[last];
        dp[start]=0;
        for(long long x=0;x<to_line[start].size();x++)
        {
            for(long long z=0;z<line_to[to_line[start][x]].size();z++)
            {
                long long next=line_to[to_line[start][x]][z];
                if(start!=next)
                {
                    dp[next]=min(dp[next],lt[to_line[start][x]][start]+lt[to_line[start][x]][next]);
                    //cout<<start<<" "<<next<<" "<<lt[to_line[start][x]][start]<<" "<<lt[to_line[start][x]][next]<<endl;
                    now.push({start,next});
                }
            }
        }
        for(;now.size()>0;)
        {
            long long now_size=now.size();
            for(long long x=1;x<=now_size;x++)
            {
                pair<long long,long long> zhong_jie=now.front();
                now.pop();
                long long sec=zhong_jie.second;
                for(long long z=0;z<to_line[sec].size();z++)
                {
                    long long nextl=to_line[sec][z];
                    for(long long u=0;u<line_to[nextl].size();u++)
                    {
                        long long next=line_to[nextl][u];
                        if(dp[next]>dp[sec]+lt[nextl][sec]+lt[nextl][next])
                        {
                            if(sec!=next)
                            {
                                dp[next]=dp[sec]+lt[nextl][sec]+lt[nextl][next];
                                //cout<<sec<<" "<<next<<" "<<lt[nextl][sec]<<" "<<lt[nextl][next]<<endl;
                                now.push({sec,next});
                            }
                        }
                    }
                }
            }
        }
        cout<<dp[last]+ans<<endl;
    }
    return 0;
}
