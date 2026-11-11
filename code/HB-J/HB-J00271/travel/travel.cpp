#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool n,w,l,z;
//priority_queue<>
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    ll xx=0,yy=0,aa=0,bb=0;
    char nj,zj;
    cin>>a>>b>>c>>d;
    for(int i=0;i<a.size();i++)
    {
        xx+=(a[i]-'0');
    }

    for(int i=0;i<b.size()-1;i++)
    {
        aa+=(b[i]-'0');
    }
    nj=b[b.size()-1];
    for(int i=0;i<c.size();i++)
    {
        yy+=(c[i]-'0');
    }

    for(int i=0;i<d.size()-1;i++)
    {
        bb+=(d[i]-'0');
    }
    zj=d[d.size()-1];
    if(xx==yy)
    {
        n=1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(aa==bb)w=1;
    else {
        cout<<n<<"000";
        return 0;
    }
    if((nj<='C'&&zj<='C')||(nj<='E'&&nj>'C'&&zj<='E'&&zj>'C'))l=1;
    else {
        cout<<n<<w<<"00";
        return 0;
    }
    if(zj>nj)swap(zj,nj);
    if((nj<='C'&&zj<='C'&&(nj-zj)==1)||(nj<='E'&&nj>'C'&&zj<='E'&&zj>'C'&&(nj-zj)==1))z=1;
    cout<<n<<w<<l<<z;
    return 0;
}
