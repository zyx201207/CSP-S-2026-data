#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,m;
int card[500001],sum[300001],ans[300001];
bool checkA()
{
    for(int i=1;i<n;i++)if(card[i]>card[i+1])return false;
    return true;
}
void play(int start)
{
    stack<int> s;
    memset(sum,0,sizeof(sum));
    for(int i=start;i<=n;i++)
    {
        if(sum[card[i]])
        {
            while(s.top()!=card[i])
            {
                sum[s.top()]--;
                s.pop();
            }
            sum[s.top()]--;
            s.pop();
        }
        s.push(card[i]);
        sum[card[i]]++;
    }
    for(int i=1;i<=m;i++)ans[i]+=sum[i];
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>card[i];
    if(checkA())
    {
        for(int i=1;i<n;i++)
        {
            if(card[i]!=card[i+1])cout<<i<<" ";
        }
        cout<<n<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)play(i);
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}