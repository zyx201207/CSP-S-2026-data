#include <iostream>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int r1,x1;
    string r2;
    string x2;
    cin>>r1>>r2>>x1>>x2;
    if(r1!=x1)
    {
        cout<<0<<0<<0<<0;
    }
    else if(r1==x1)
    {
        cout<<1;
        if(r2[0]==x2[0]&&r2[1]==x2[1])
        {
            cout<<1;
            if(r2[2]>='A'&&r2[2]<='C'&&x2[2]>='A'&&x2[2]<='C'){
                cout<<1;
                if(x2[2]==r2[2]-1||x2[2]==r2[2]+1){
                    cout<<1;
                }
                else
                    cout<<0;
            }
            else if(r2[2]>='D'&&r2[2]<='F'&&x2[2]>='D'&&x2[2]<='F'){
                cout<<1;
                if(x2[2]==r2[2]-2||x2[2]==r2[2]+2){
                    cout<<1;
                }
                else
                    cout<<0;
            }
            else
                cout<<0<<0;
        }
        else
            cout<<0<<0<<0;
    }
    return 0;
}
