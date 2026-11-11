#include<bits/stdc++.h>
using namespace std;
long long ans,cnt;
string z;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;

    while(n--)
    {
        int ge;
        char a;
        cin>>ge>>a;
        ans+=ge;
        for(int i=0;i<ge;i++)
        {
            z+=a;
        }
    }
    for(int i=0,j=ans-1;i<ans/2;i++,j--)
    {
        if(i!=j)
        {
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
