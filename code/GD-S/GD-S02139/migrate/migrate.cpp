#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
ifstream fin("migrate.in");
ofstream fout("migrate.out");
#define cin fin
#define cout fout
long long c,T,l,r,s,d;
long long x[5001],ans,cur;
bool flag;
void dfs(long long now,long long cnt)
{
    if(now==r)
    {
        if(cnt<s)
        	s=cnt,cur=1;
        else if(cnt==s)
        	cur++;
        return;
    }
    for(long long i=now+1;i<=r;i++)
    {
        if(x[i]-x[now]<=d)
            dfs(i,cnt+1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>T;
    while(T--)
    {
        ans=0;
        long long n;
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
            cin>>x[i];
        for(l=1;l<=n;l++)
            for(long long len=1;l+len<=n;len++)
            {
            	r=len+l;
            	s=INT_MAX;
            	cur=0;
				dfs(l,0);
				if(s==LONG_LONG_MAX)
					continue;
                if(cur==2)
                {
                	ans++;
				}
            }
        cerr<<endl;
        cout<<ans<<endl;  
    }
}
