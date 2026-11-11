#include <iostream>
#include <cstring>
using namespace std;
string s=" ";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int len;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        while(a--)
        {
            s=s+c;
        }
        len+=a;
    }
    int cnt=0;
    for(int i=1;i<=len/2;i++)
    {
        if(s[i]!=s[len-i+1])
            cnt+=1;
    }
    cout<<cnt;
    return 0;
}
