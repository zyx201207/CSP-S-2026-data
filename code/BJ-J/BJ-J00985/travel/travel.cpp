#include<iostream>
using namespace std;
int a,b,qq,ww,o,p;
string q,w;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>q>>b>>w;
    if(a==b) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    qq=(q[0]-'0')*10+(q[1]-'0');
    ww=(w[0]-'0')*10+(w[1]-'0');
    if(qq==ww) cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    o=q[2]-'A'+1;
    p=w[2]-'A'+1;
    if((o<=3&&o>=1&&p<=3&&p>=1)||((o==4||o==6)&&(p==4||p==6))) cout<<1;
    else cout<<0;
    if((o==1&&p==2)||(o==2&&p==1)||(o==2&&p==3)||(o==3&&p==2)||(o==4&&p==6)||(o==6&&p==4)) cout<<1;
    else cout<<0;

    return 0;
}
