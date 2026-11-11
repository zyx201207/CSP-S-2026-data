#include<iostream>
using namespace std;
int n;
string s=" ";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int lo=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        string c;
        cin>>x>>c;
        string tmp="";
        for(int j=1;j<=x;j++)
        {
            lo++;
            tmp+=c;
        }
        s+=tmp;
    }
    int l=1;
    int r=lo;
    int cnt=0;
    while(l<=r)
    {

        if(s[l]!=s[r])
        {
            cnt++;
        }
        l++;r--;
    }
    cout<<cnt;
}
