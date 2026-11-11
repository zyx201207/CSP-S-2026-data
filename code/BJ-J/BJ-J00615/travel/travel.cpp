#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x1,yy1,x2,y2;
char x3,y3;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x1>>x2>>x3>>yy1>>y2>>y3;
    if(x1==yy1)
    {
        if(x2==y2)
        {
            if((x3<='C'&&y3<='C')||(x3>'C'&&y3>'C'))
            {
                if(abs(y3-x3)==1)cout<<"1111"<<endl;
                else cout<<"1110"<<endl;
            }
            else cout<<"1100"<<endl;
        }
        else cout<<"1000"<<endl;
    }
    else cout<<"0000"<<endl;
    return 0;
}
