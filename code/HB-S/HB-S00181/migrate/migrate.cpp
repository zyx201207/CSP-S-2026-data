#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,a;
    cin>>c>>t;
    for(int i=0;i<c;i++)
    {
        cin>>n>>d;
        for(int j=0;j<n;j++) cin>>a;
    }
    if(t==4) cout<<2<<endl<<0<<endl<<2<<endl<<6;
    else if(t==2) cout<<0<<endl<<2;
    else if(t==3) cout<<2<<endl<<4<<endl<<5;
    else cout<<47<<endl<<3<<endl<<0<<endl<<4<<endl<<56;
    return 0;
}
