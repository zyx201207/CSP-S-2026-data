#include<bits/stdc++.h>
using namespace std;
string n,n1,m,m1;
int q1=0,q2=0,q3=0,q4=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>n1>>m>>m1;
    if(n!=m)
    {
        cout<<"0000";
        return 0;
    }
    else
        q1++;
    if(n1[0]==m1[0]&&n1[1]==m1[1])
        {
            q2++;
            if(((n1[2]=='A'||n1[2]=='B'||n1[2]=='C')&&(m1[2]=='A'||m1[2]=='B'||m1[2]=='C'))||((n1[2]=='D'||n1[2]=='F')&&(m1[2]=='D'||m1[2]=='F')))
            {
               q3++;
               if((n1[2]=='A'&&m1[2]=='B')||(n1[2]=='B'&&m1[2]=='A')||(n1[2]=='B'&&m1[2]=='C')||(n1[2]=='C'&&m1[2]=='B')||(n1[2]=='D'&&m1[2]=='F')||(n1[2]=='F'&&m1[2]=='D'))
                 q4++;
            }
        }
    cout<<q1<<q2<<q3<<q4;
    return 0;
}
