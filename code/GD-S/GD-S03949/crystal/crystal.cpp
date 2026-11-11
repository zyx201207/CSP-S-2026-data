#include <bits/stdc++.h>
using namespace std;
long long a[1000000005];
long long b[1000000005];
long long maxlocation,findlocation,ans,m,n,tmp;
int main()
{
    ios::sync_with_stdio(0);
    //ios::stuios.sync(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    cin>> n >> m;
    //cout << 1;
    for(long long i=1;i<=n;i++)
    {
        //cout <<1;
        cin>>tmp;
        a[i]=tmp;
        b[tmp]++;
        if(maxlocation<b[tmp])
        {
            maxlocation=tmp;
        }
        tmp=0;
    }
    if(maxlocation == 1)
    {
        
        maxlocation=long(n/2)+1;
    }
    //cout << maxlocation << "\n" << findlocation << "\n" << m;
    findlocation=1;
    while(m>0 && findlocation>=1)
    {
        //m-=a[maxlocation];
        ans+=b[maxlocation];
        findlocation=maxlocation-1;
        //cout << findlocation<<"\n";
        //cout << findlocation << endl;
        //cout << ans << " ";
        if(b[findlocation]==0)
        {
            findlocation-=1;
            //cout << findlocation << 1 << endl;
        }
        if((maxlocation-findlocation) <=m && b[findlocation] !=0)
        {
            for(long long j=0;j<b[findlocation];j++)
            {
                if(m>0)
                {
                    m-=(a[maxlocation]-a[findlocation]);
                    ans+=1;
                    //cout << ans << " " <<m << " " << a[maxlocation]-a[findlocation] << endl ;
                }
                else{
                    break;
                }
            }
            //m-=(maxlocation-findlocation);
            //ans+=1;
        }
        else{
            break;
        }

    }
    cout <<ans;
    return 0;
}
