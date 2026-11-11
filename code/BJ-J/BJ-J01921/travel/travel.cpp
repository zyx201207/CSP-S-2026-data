#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(((a==c)&&(b[0]==d[0])&&(b[1]==d[1])))
        {

            cout<<"1";
            if(((a==c)&&(b[0]==d[0])&&(b[1]==d[1]))&&((b[2]-'C'>0)==(d[2]-'C'>0)))
            {

                cout<<"1";
                if(((int(b[2])-int(d[2]))==1)||((int(b[2])-int(d[2]))==-1))
                {

                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    //cout<<((a==c)&&(b[0]==d[0])&&(b[1]==d[1]));
    //cout<<((a==c)&&(b[0]==d[0])&&(b[1]==d[1]))&&((b[2]-'C'>0)==(d[2]-'C'>0));
    //cout<<(((int(b[2])-int(d[2]))==1)||((int(b[2])-int(d[2]))==-1));
    //cout<<b[2]<<d[2]<<b[2]-d[2]<<abs(int(b[2]-d[2]))<<((int(b[2])-int(d[2]))==-1)<<":"<<((int(b[2])-int(d[2]))==1)||((int(b[2])-int(d[2]))==-1);
}
