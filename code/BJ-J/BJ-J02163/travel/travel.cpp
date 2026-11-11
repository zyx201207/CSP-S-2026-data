#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c>>d;
    int hg,qc;
    hg=(a[0]-'0')*10+a[1]-'0';
    qc=(c[0]-'0')*10+c[1]-'0';
    if(hg==qc) cout<<"1"<<" ";
    else
    {
        cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0";
        return 0;
    }
    hg=0;
    qc=0;
    hg=(b[0]-'0')*10+b[1]-'0';
    qc=(d[0]-'0')*10+d[1]-'0';
    if(hg==qc) cout<<"1"<<" ";
    else
    {
        cout<<"0"<<" "<<"0"<<" "<<"0";
        return 0;
    }
    if(b[2]=='F')
    {
        if(d[2]=='D')
        {
            cout<<"1"<<" "<<"1";
            return 0;
        }
        else
        {
            cout<<"0"<<" "<<"0";
            return 0;
        }
    }
    if(d[2]=='F')
    {
        if(b[2]=='D')
        {
            cout<<"1"<<" "<<"1";
            return 0;
        }
        else
        {
            cout<<"0"<<" "<<"0";
            return 0;
        }
    }
    int x,y,z;
    x=b[2]-'A'+1;
    y=d[2]-'A'+1;
    if(x>y)
    {
        if((x-y)!=1) cout<<1<<" "<<0;
        else cout<<1<<" "<<1;
    }
    else if(y>x)
    {
        if((y-x)!=1) cout<<1<<" "<<0;
        else cout<<1<<" "<<1;
    }
    return 0;if((x-y)!=1) cout<<1<<" "<<0;
        else cout<<1<<" "<<1;
}
