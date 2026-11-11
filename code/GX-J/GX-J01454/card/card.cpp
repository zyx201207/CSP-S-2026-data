#include <bits/stdc++.h>

using namespace std;
int s[500100]={0};
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    for(int i=0;i<n;i++){
        cout << s[i] <<" ";
    }

    return 0;
}
