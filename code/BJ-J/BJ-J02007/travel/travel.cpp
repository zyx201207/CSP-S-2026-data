#include <iostream>
#include <cstring>
using namespace std;
string c1,c2,s1,s2;
bool b[100];
int sum[10010];
int main()
{
    cin>>c1>>s1>>c2>>s2;
    if(c1=="01"||c1=="16"||c2=="01"||c2=="16")
    {
        cout<<"0000";
        return 0;
    }
    if(c1==c2)
    {
        b[1]=1;
        if(s1.size()-1==s2.size()-1)
        {
            b[2]=1;
            if(s1==s2)
            {
                b[3]=1;
                if(s1.size()-'1'==s2.size()||s1.size()+'1'==s2.size()||s1.size()-'1'==s2.size()||s1.size()-'1'==s2||)
                    b[4]=1;
            }

        }
    }
    for(int i=1;i<=4;i++) cout<<b[i];
}
