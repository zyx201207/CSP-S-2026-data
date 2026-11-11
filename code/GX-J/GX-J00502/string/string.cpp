#include <iostream>
using namespace std;
//freopen(string.in && string.out);
//freopen(string.stdin.in && string.stdout);
int n,m,ans,a[100005];
int main()
{
    cin>>n>>a>>ans;
    for(int i=n;i>=1;i++)
    {
        while(m>=n)
        {
            continue;
        }
        if(n==2 && m==a)
        {
            ans++;
        }
        else if(n==i && m==a)
        {
            cout<<1<<endl;;
        }

    }
    return 0;
}
