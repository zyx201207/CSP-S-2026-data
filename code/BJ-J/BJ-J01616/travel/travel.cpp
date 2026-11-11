#include<iostream>
#include<cmath>
using namespace std;
string c1,s1,c2,s2;
bool q1,q2,q3,q4;
const int a[6]={0,0,0,1,1,1};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool q1=(c1==c2);
    bool q2=(q1&&(s1[0]==s2[0]&&s1[1]==s2[1]));
    bool q3=(q2&&(a[s1[2]-'A']==a[s2[2]-'A']));
    if(s1[2]=='D')s1[2]=='E';
    if(s2[2]=='D')s2[2]=='E';
    bool q4=(q3&&(abs(s1[2]-s2[2])==1));
    cout<<q1<<q2<<q3<<q4;
    return 0;
}
