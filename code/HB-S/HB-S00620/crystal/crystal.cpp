#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m=0,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    a[0]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    long long now=0;
    int anns=1;
    for(int i=1,j=2;j<=n;j++)
    {
        //cout<<i<<" "<<j<<" "<<j-i+1<<" "<<now<<endl;
        while((now+(a[j]-a[j-1])*(j-i))>m)
        {
            //if(j==5)cout<<i<<" "<<j<<" "<<j-i+1<<" "<<now<<endl;
            now-=(a[j-1]-a[i]);
            i++;
            //if(j==5)cout<<i<<" "<<j<<" "<<j-i+1<<" "<<now<<endl;
            if(i==j)
            {
                now=0;
                break;
            }
        }
        now+=(a[j]-a[j-1])*(j-i);
        //cout<<i<<" "<<j<<" "<<j-i+1<<" "<<now<<endl;
        anns=max((j-i+1),anns);
    }
    cout<<anns;
    return 0;
}
//5 8 -3 -1 2 2 7
