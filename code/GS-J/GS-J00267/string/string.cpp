#include<bits/stdc++.h>
using namespace std;
int main()
{
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
        int n;
        long long cc=0, k;
        char x;
        string s;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>k>>x;
            while(k--)s+=x;
        }
        long long len=s.size();
        for(long long  i=0;i<len/2+1;i++)
        {
            if(s[i]!=s[len-i-1])cc++;
        }
        cout<<cc;
        return 0;
}
