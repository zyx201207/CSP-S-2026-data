#include<bits/stdc++.h>
//define int long long
using namespace std;
int cnt_end[300005];
int cnt_zong[300005];
int jicheng[300005];
int arr[500005];
int recent[300005];
int brr[300005];
int cmp(int a,int b)
{
    return recent[a]<recent[b];
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        cnt_end[arr[i]]++;
        recent[arr[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        jicheng[i]=arr[recent[i]+1];
        brr[i]=i;
    }
    sort(brr+1,brr+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        cnt_zong[brr[i]]+=cnt_end[brr[i]];
        cnt_end[jicheng[brr[i]]]+=cnt_end[brr[i]];
    }
    for(int i=1;i<=m;i++)
        cout<<cnt_zong[i]<<" ";
    return 0;
}
