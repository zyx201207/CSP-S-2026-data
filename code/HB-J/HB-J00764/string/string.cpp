#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
int n;
long long cnt=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        long long cnt;
        char t;
        scanf("%lld %c",&cnt,&t);
        getchar();
        for(int i=1;i<=cnt;i++)
            s+=t;
    }
    int j=s.size()-1;
    for(int i=0;i<s.size() && i!=j;i++)
    {
        if(s[i]!=s[j])
        {
            cnt++;
        }
        j--;
    }
    cout << cnt;
    return 0;
}
