#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin>>a>>x>>b>>y;
    int t=0;
    for(int i=0;i<2;i++)
    {
        if(a[i]==b[i]) t++;
    }
    if(t==2)
    {
        cout<<1;
        int ans=0;
        for(int i=0;i<2;i++)
        {
            if(x[i]==y[i]) ans++;
        }
        if(ans==2)
        {
            cout<<1;
            if(x[2]<='C'&&y[2]<='C') cout<<1;
            else if(x[2]=='D'&&y[2]=='F'||x[2]=='F'&&y[2]=='D') cout<<1;
            else cout<<0;
            if(x[2]=='D'&&y[2]=='F'||x[2]=='F'&&y[2]=='D'||x[2]=='A'&&y[2]=='B'||x[2]=='B'&&y[2]=='C'||y[2]=='A'&&x[2]=='B'||y[2]=='B'&&x[2]=='C') cout<<1;
            else cout<<0;
        }
        else cout<<"000";
    }
    else cout<<"0000";


    return 0;
}
