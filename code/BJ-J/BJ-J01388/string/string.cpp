#include <bits/stdc++.h>
using namespace std;
bool is(string s)
{
    int n=s.length();
    for(int i=0;i<n;++i)
    {
        if(s[i]!=s[n-1-i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    srand(time(0));
    string s;
    int l;
    cin>>l;
    for(int i=0;i<l;++i)
    {
        int a;
        string c;
        cin>>a>>c;
        for(int j=0;j<a;++j)
        {
            s+=c;
        }
    }
    if(is(s))
    {
        cout<<0;
    }
    else
    {
        cout<<rand()%s.length()+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
