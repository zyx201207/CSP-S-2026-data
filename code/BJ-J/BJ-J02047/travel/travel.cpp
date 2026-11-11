#include <iostream>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,l1,l2,s1,s2;
    string i1,i2;
    cin>>c1>>i1>>c2>>i2;
    l1=(i1[0]-'0')*10+(i1[1]-'0');
    l2=(i2[0]-'0')*10+(i2[1]-'0');
    s1=i1[2]-'A'+1;
    s2=i2[2]-'A'+1;
    //cout<<c1<<" "<<c2<<" "<<l1<<" "<<l2<<" "<<s1<<" "<<s2<<endl;
    bool a=0,b=0,c=0,d=0;
    if(c1==c2)
    {
        a=1;
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a&&l1==l2)
    {
        b=1;
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a&&b&&((s1<=3&&s2<=3)||(s1>3&&s2>3)))
    {
        c=1;
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a&&b&&c&&(s1+1==s2||s2+1==s1))
    {
        d=1;
        cout<<1;
    }
    else{
        cout<<0;
    }


    return 0;
}
