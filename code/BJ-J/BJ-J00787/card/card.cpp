#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N];
int b[M];
vector<int> c(M);
stack<int> s;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){//对于每一局
        while(!s.empty())s.pop();
        for(int j=0;j<m;j++)c[j]=0;
        for(int j=i;j<n;j++){
            if(c[a[j]]!=0){
                while(s.top()!=a[j])s.pop();
                s.pop();
            }
            s.push(a[j]);
            c[a[j]]++;
        }
        int x1=s.size();
        for(int j=0;j<x1;j++)cout<<s.top()<<" ",b[s.top()]++,s.pop();
        cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<" ";
    return 0;
}
