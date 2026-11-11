#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    char c;
    vector<char> s;
    for(int i=0;i<n;i++)
    {
        cin>>a>>c;
        for(int j=0;j<a;j++)
        {
            s.push_back(c);
        }
    }
    int l=s.size()/2;
    int cnt=0;
    for(int i=0;i<=l;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}