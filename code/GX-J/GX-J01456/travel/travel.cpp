#include <iostream>

using namespace std;

int main()
{   freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    string c1;
    string c2;
    string y1;
    string y2;
    cin>>c1>>c2>>y1>>y2;
    string a;
    int f=0;
    int e=0;
    if(c1==y1)
    {
       cout<<"1";
        for(int i=0; i<2; i++)
        {   //cout<<c2[i]<<endl<<y2[i]<<endl;
            if(c2[i]==y2[i])
            {
                f=1;
            }
            else
            {
               f=0;
            }
        }
        if(f==1)
        {

            cout<<"1";
            if((c2[2]!='F' && c2[2]!='D'&&y2[2]!='F' && y2[2]!='D') || (c2[2]!='A' && c2[2]!='B' && c2[2]!='C' && y2[2]!='A' && y2[2]!='B' && y2[2]!='C'))
            {
               cout<<"1";
            // cout<<y2[2]+'0'<<" "<<c2[2]+'1';
                if(c2[2]+'0'==y2[2]+'1'  ||  c2[2]+'1'==y2[2]+'0' )
                {
                           cout<<"1";
                }
                else
                {
                    e=0;
                }
            }
           else
           {
              e=1;
           }

        }
        else
        {
            e=2;
        }

    }
    else
    {
       e=3;
    }
    for(int i=e;i>=0;i--)
    {
        cout<<"0";
    }


}



