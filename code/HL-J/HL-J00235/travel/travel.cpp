#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,c3,c4;
    cin>>c1>>c2>>c3;
    if(c1==c3)
    {
        cout<<"1";

    }
    else
    {

        cout<<"0";
    }
    for(int i=1;i<3;i++)
        {
            if(c2[i]==c4[i])
            {
                cout<<"1";
            }
            else
            {
                cout<<"0";
            }
            if((c2[i]==c4[i]=="A"||c2[i]==c4[i]=="B"||c2[i]==c4[i]=="C")||(c2[i]==c4[i]=="D")||c2[i]==c4[i]=="F")
            {
                cout<<"1";
            }
            else
            {
                cout<<"0";
            }
            if((c2[i]=="A"&c4[i]=="B")||(c2[i]=="B"&c4[i]=="C")||(c2[i]=="D"&c4[i]=="F"))
            {
                cout<<"1";
                return 0;

            }
            else
            {

                cout<<"0";
                return 0;
            }

        }
    fclose(stdin);
    fclose(stdout);
    return 0;
    }
