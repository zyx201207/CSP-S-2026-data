#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;
int arr[N];
bool col[M];
vector<int> paizhuo;
int n,m;
int ans[N];
void solve(int ju)
{
    for(int i=ju;i<=n;i++)
    {
        if(col[arr[i]])
        {
            for(int j=paizhuo.size()-1;j>=0;j--)
            {
                col[j]=0;
                paizhuo[j]=0;
                if(arr[i]==paizhuo[j])
                    break;
            }
        }
        paizhuo.push_back(arr[i]);
        col[arr[i]]=1;
    }
    for(auto i : paizhuo)
    {
        ans[i]++;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int ju=1;ju<=n;ju++)
    {
        paizhuo.clear();
        memset(col,0,sizeof(col));
        solve(ju);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
