#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
const int M=3*1e5+5;
int n,m;
int a[N];
map<int,int> ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        stack<int> st;
        map<int,bool> ma;
        for(int j=i;j<=n;j++)
        {
            if(!ma[a[j]]) ma[a[j]]=true;
            else
            {
                while(st.top()!=a[j]) 
                {
                    ma[st.top()]=false;
                    st.pop();
                }
                st.pop();
            }
            st.push(a[j]);
        }
        for(auto u:ma) if(u.second==true) ans[u.first]++;
    }
    for(auto u:ans) cout<<u.second<<' ';
    cout<<"\n";
    return 0;
}