#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
long long pw[100005]={1};
int answer=0;
void dfs(int left,int k,int sum)
{
    if(answer!=0&&sum>answer)return;
    if(k>m)
    {
        answer=max(answer,sum);
        return;
    }
    if(left>n)return;
    for(int i=left;i<=n;i++)
    {
        int x=sum;
        x&=a[i];
        dfs(i+1,k+1,x);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        dfs(i+1,1,a[i]);
    }
    cout<<answer;
    return 0;
}
