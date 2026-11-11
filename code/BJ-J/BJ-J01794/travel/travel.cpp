#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    char c1,c2,c3;
    cin>>c1>>c2;
    int p1=(c1-'0')*10+(c2-'0');
    cin>>c1>>c2>>c3;
    int r1=(c1-'0')*10+(c2-'0');
    int A=c3-'A';
    cin>>c1>>c2;
    int p2=(c1-'0')*10+(c2-'0');
    cin>>c1>>c2>>c3;
    int r2=(c1-'0')*10+(c2-'0');
    int B=c3-'A';

    if(p1!=p2)
    {
        cout<<"0000\n";
        return 0;
    }
    cout<<1;
    if(r1!=r2)
    {
        cout<<"000\n";
        return 0;
    }
    cout<<1;
    if(!((3-A>0)&&(3-B>0)||(3-A)<=0&&(3-B)<=0))
    {
        cout<<"00\n";
        return 0;
    }
    cout<<1;
    if(abs(A-B)==1) cout<<"1\n";
    else cout<<"0\n";

    return 0;
}
