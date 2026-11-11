#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long len;
struct node
{
    long long sl;
    string zm;
};
node a[100005];
string b[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i=n;i++)
    {
        cin>>a[i].sl>>a[i].zm;
        for(int i=1en;i<=len+a[i].sl;i++)
        {
            b[i]=a[i].zm;
        }
        len+=a[i].sl;

    }
    for(int i=1;i<=len/2;i++)
    {
        if(b[i]!=b[len-i+1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
