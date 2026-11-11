#include<bits/stdc++.h>
using namespace std;
int n;
long long a;
long long sum;
char c;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 0;i < n;i ++)
    {
        cin >> a >> c;
        sum += a;
        for(int j = 0;j<a;j++)
        {
            s.push_back(c);
        }
    }
    if(sum%2==0)
    {
        string l=s.substr(0, sum/2);
        string m=s.substr(sum/2,sum-1);
        reverse(l.begin(),l.end());
        long long len=m.size();
        long long ans=0;
        for(int i=0;i<len;i++)
        {
            if(l[i]!=m[i]) ans++;
            else continue;
        }
        cout<<ans;
        return 0;
    }
    else
    {
        string l=s.substr(0, sum/2);
        string m=s.substr(sum/2+1,sum);
        reverse(l.begin(),l.end());
        long long len=m.size();
        long long ans=0;
        for(int i=0;i<len;i++)
        {
            if(l[i]!=m[i]) ans++;
            else continue;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
