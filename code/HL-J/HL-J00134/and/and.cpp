#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int s[3000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
        maxn=max(s[i],maxn);
    }if(m==1) cout<<maxn;
    return 0;
}
