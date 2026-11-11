#include <bits/stdc++.h>
using namespace std;
int a[500005]={0};stack<int> st;int isinst[500005]={0};int ans[500005]={0};int n,m;
void popf()
{
    isinst[st.top()]--;
    st.pop();
}void init(){
    while(!st.empty())  st.pop();
    for(int i=1;i<=n;i++) isinst[i]=0;
    return ;
}
void popxright(int x){
    if(!isinst[x])  return ;
    while(!st.empty())
    {
        if(st.top()==x){popf();if(!isinst[x]){return ;}}
        else{popf();}
    }
}
bool tt[500005]={0};
void ps(int x)
{
    st.push(a[x]);
    isinst[a[x]]++;
    return ;
}
void checkend()
{
    while(!st.empty())
    {
        tt[st.top()]=1;
        popf();
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int games=1;games<=n;games++)
    {
        init();
        for(int i=games;i<=n;i++)
        {
            popxright(a[i]);
            ps(i);
        }
        checkend();
        for(int i=1;i<=m;i++)
        {
            if(tt[i]==1)    ans[i]++;
            tt[i]=0;
        }
    }
    for(int i=1;i<=m;i++)
        {
            cout << ans[i] << " ";
        }
    return 0;
}