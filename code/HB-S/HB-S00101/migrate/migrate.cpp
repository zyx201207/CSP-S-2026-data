#include <bits/stdc++.h>
using namespace std;
int c,t;
int num;
int lengh;
int island[1000000];
bool flag[1000000];
int tongtou[1000000];
int sum[1000000];
int answer;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);cin>>c>>t;
    for(int ceshi = 1;ceshi<=t;ceshi++)
    {for(int i = 1;i<=num;i++)
    {
    sum[i] = 1;
    }

    cin>>num>>lengh;
    for(int i = 1;i<=num;i++)
    {
        cin>>island[i];
        island[i]--;
    }
    for(int i = 2;i<=num;i++)
    {
        island[i] = island[i]-island[i-1];
    }

    for(int i = 1;i<=num;i++)
    {
        if(island[i]+tongtou[i-1]>lengh)
        tongtou[i] = island[i];
        else tongtou[i] = tongtou[i-1]+island[i];
    }

    for(int i = 3;i<=num;i++)
    {
        if(tongtou[i]!=island[i])flag[i] = true;
    }
    for(int i = 1;i<=num;i++)
    {
        int i1 = i;
        int cnt = 0;
        for(int j = i;j<=num;j++)
        {
            int j1 = j;
            if(flag[j1] == true)
            {
                if(cnt!=0)
                sum[i] = sum[i]*cnt;
                cnt = 0;
            }
            if(flag[j1] == false)cnt++;
        }
        if(sum[i] == 2)answer++;
    }
    cout<<answer;

    }

return 0;
}
