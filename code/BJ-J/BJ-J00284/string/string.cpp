#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n;
    cin >> n;long long now=1;
    for(int i=1;i<=n;i++)
    {
        int ai;cin >> ai;
        char t;cin >> t;
        for(int j=now;j<=now+ai-1;j++) 
        {
            s[j]=t;
        }
        now+=ai;
    }int ans=0;now--;
    for(int i=1;i<=now/2;i++)
    {
        int pl=(now+1)/2;
        //cout << "debug|" << s[i] << " " << s[now+1-i] << endl;
        if(s[i]!=s[now+1-i]) ans++;
    }
    cout << ans;
    return 0;
}