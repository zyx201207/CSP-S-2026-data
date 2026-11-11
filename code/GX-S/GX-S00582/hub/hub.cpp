#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,i,j=0;
    cin>>c>>t;
    for(i=1;i<=t;i++)
    {
        cout<<j<<endl;
        if(i==t/2)
        {
           j--;
        }
        else
        {
            j++;
        }
    }
    return 0;
}

    return 0;
}
