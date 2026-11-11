#include <iostream>
using namespace std;
//freopen(card.in && card.out);
//freoprn(card.stdin && card.stdout);
int n,a,k;
int ans=0;
int main()
{
    cin>>n,a,k;
    for(int i=1;i<=n;i++)
    {
        if(k==j)
        {
            ans++;
            continue;
        }
        else if(k!=j)
        {
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
