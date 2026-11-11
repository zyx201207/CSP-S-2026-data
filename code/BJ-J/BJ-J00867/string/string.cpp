#include<iostream>
using namespace std;
char s[1500000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,ans=0,k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long num;
        char a;
        cin>>num>>a;
        for(int j=0;j<num;j++)
        {
            s[k]=a;
            k++;
        }
    }
    for(int i=0;i<k/2;i++)
    {
        if(s[i]!=s[k-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
