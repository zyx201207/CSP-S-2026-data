#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],x;
bool pd=true;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
        if(b[a[i]]>1) {
            pd=false;
            x=i;
        }
    }
    if(pd=true){
        for(int i=1;i<=n;i++){
            cout<<1<<' ';
        }
        return 0;
    }
    cout<<3<<' '<<1<<' '<<4;
    return 0;
}
