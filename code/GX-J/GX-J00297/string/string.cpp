#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    int a;string c,huiwen,hw;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        while(a==0){
            huiwen+=c;
            a--;
        }
    }
    for(int i=huiwen.size();i>=1;i--)
    {
        hw+=huiwen[i];
    }
    if(hw==huiwen) cout<<0;
    else{
        for(int a=1,b=huiwen.size();a<=huiwen.size()/2||a==b;a++,b++)
        {
            if(huiwen[a]!=huiwen[b]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

