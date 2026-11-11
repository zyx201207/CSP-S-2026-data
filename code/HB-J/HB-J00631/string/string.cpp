#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s=" ";
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a;
        string c;
        cin >> a >> c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    int f=s.size()-1,cnt=0;
    for(int i=1;i<=f/2+1;i++)
    {
        if(s[i]==s[f-i+1])
        {
            continue;
        }
        else
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
