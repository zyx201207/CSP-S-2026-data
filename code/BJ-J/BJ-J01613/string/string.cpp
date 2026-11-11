#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string str;
    long long cnt = 0;
    string t;
    long long num;
    long long n;
    cin>>n;
    for(long long i = 1;i <= n;i++)
    {
        cin>>num;
        cin>>t;
        while(num--)
            str+=t;
    }
    for(long long i = 0;i < str.length();i++)
    {
        if(str[str.length()-1-i] != str[i])
        {
            cnt++;
        }
    }
    cout<<cnt/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
