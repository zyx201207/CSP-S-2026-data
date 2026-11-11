#include <bits/stdc++.h>
using namespace std;
int n,m,a,cnt;
vector<string> s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++){
        int x;
        string y;
        cin>>x>>y;
        for (int j=1; j<=x; j++){
            s[j]=y;
        }
    }
    for (int i=1; i<=n; i++){
        if (s[i]==s[n]) cout<<"0";
        else{
            s[n]=s[i];
            cnt++;
        }
        n--;
    }
    cout<<cnt;
    return 0;
}
