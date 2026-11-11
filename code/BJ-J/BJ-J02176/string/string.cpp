#include<iostream>
using namespace std;

string s="",c;
int a,n,b,cnt;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    b=s.size();
    if(b%2==0)
    {
        for(int i=0;i<=b/2-1;i++)
        {
            if(s[i]!=s[b-i-1]) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
