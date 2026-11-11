#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string1.in","r",stdin);
    freopen("string1.out","w",stdout);

    int n,m,o_number=0;
    char str;
    string strs;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>m;
        cin>>str;

        for(int j=1;j<=m;j++)
        {
            strs+=str;
        }
    }

    string strs_a,strs_b;

    int hl=strs.length()/2;

    for(int i=0;i<hl;i++)
    {
        strs_a+=strs[i];
    }
    for(int i=strs.length()-1;i>=strs.length()-hl;i--)
    {
        strs_b+=strs[i];
    }

    for(int i=0;i<hl;i++)
    {
        if(strs_a[i]!=strs_b[i]) o_number+=1;
    }

    cout<<o_number<<endl;

    return 0;
}

