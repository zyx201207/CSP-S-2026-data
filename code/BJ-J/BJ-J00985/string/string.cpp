#include<iostream>
using namespace std;
int n,a[200001];
long long l=0,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int tmp=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        l+=x;
        char dfg;
        cin>>dfg;
        int tmpp=tmp+x;
        for(;;)
        {
            if(tmp==tmpp) break;
            a[tmp]=dfg-'a'+1;
            tmp++;
        }
    }
    int i=1,j=l;
    for(;;i++,j--)
    {
        if(i>j) break;
        if(a[i]!=a[j]) ans++;
    }
    cout<<ans;
    return 0;
}
