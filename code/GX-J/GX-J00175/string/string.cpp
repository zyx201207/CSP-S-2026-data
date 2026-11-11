#include <bits/stdc++.h>

using namespace std;
int m[10000000000];
char b[1000000000];
int main()
{
    freopen("string","r",stdin);
    freopen("string","w",stdout);
    int n;
    cin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>m[i]>>b[i];
    }
    long long sum=0;
    long long i=1,j=n;
    while(i<j)
    {
        int q=min(m[i],m[j]);
        if(b[i]!=b[j])
        {
            sum+=q;
        }
        if(q==m[i])
        {
            m[j]-=q;
            i++;
        }
        if(q==m[j])
        {
            m[i]-=q;
            j--;
        }
    }
    cout<<sum;
    return 0;
}
