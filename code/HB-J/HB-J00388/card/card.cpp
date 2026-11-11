#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],cnt[M];
int ans[N];
void Play(int Idx)
{
    stack<int>st;
    for(int i=Idx;i<=n;i++)
    {
        if(cnt[a[i]])
        {
            while(!st.empty()&&st.top()!=a[i]) cnt[st.top()]--,st.pop();
            if(!st.empty()&&st.top()==a[i]) st.pop(),cnt[a[i]]--;
        }
        st.push(a[i]),cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++)
        if(cnt[i]) ans[i]++,cnt[i]=0;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) Play(i);
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
