#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int cnt[M];
int game[N];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)//n局游戏
    {
        memset(game,0,sizeof(game));
        int last=0;
        for(int j=i;j<=n;j++)
        {
            int k=a[j];
            for(int idx=1;idx<=last;idx++)
            {
                if(game[idx]==k)
                {
                    last=idx-1;
                    break;
                }
            }
            last++;
            game[last]=a[j];
        }
        // cout<<"第"<<i<<"局";
        for(int j=1;j<=last;j++)
        {
            // cout<<" "<<game[j];
            cnt[game[j]]++;
        }
        // cout<<"\n";
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;

    fclose(stdin);
    fclose(stdout);
}