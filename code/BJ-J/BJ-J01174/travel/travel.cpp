#include<iostream>
#include<algorithm>
using namespace std;
bool near(char x,char y)
{
    int t1=x-'A'+1,t2=y-'A'+1;
    if(t1==6) t1=5;
    if(t2==6) t2=5;
    if(abs(t1-t2)<=1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s1,s2,c1,c2,s4,c4;
    char s3,c3;
    cin>>s1>>s2>>s3>>c1>>c2>>c3;
    if(s3=='A'||s3=='B'||s3=='C') s4=0;
    if(s3=='D'||s3=='F') s4=1;
    if(c3=='A'||c3=='B'||c3=='C') c4=0;
    if(c3=='D'||c3=='F') c4=1;
    if(s1==c1)
    {
        cout<<1;
        if(s2==c2)
        {
            cout<<1;
            if(s4==c4)
            {
                cout<<1;
                if(near(s3,c3))
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
