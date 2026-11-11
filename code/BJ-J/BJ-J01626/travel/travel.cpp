#include <iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    string s1,s2;
    cin>>a>>b>>s1>>c>>d>>s2;
    int ans=0;
    if(a==c)
    {
        ans+=1000;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(b==d)
    {
        if((s1=="A"&&s2=="B")||(s1=="A"&&s2=="C")||(s1=="A"&&s2=="D")||(s1=="A"&&s2=="F")||(s1=="B"&&s2=="A")||(s1=="B"&&s2=="C")||(s1=="B"&&s2=="D")||(s1=="B"&&s2=="F")||(s1=="C"&&s2=="A")||(s1=="C"&&s2=="B")||(s1=="C"&&s2=="D")||(s1=="C"&&s2=="F")||(s1=="D"&&s2=="A")||(s1=="D"&&s2=="B")||(s1=="D"&&s2=="C")||(s1=="D"&&s2=="F")||(s1=="F"&&s2=="A")||(s1=="F"&&s2=="B")||(s1=="F"&&s2=="C")||(s1=="F"&&s2=="D"))
        {
            ans+=110;
            if((s1=="A"&&s2=="B")||(s1=="B"&&s2=="C")||(s1=="B"&&s2=="A")||(s1=="D"&&s2=="F")||(s1=="F"&&s2=="D")||(s2=="B"&&s1=="C"))
            {
                ans+=1;
            }
        }
        else
        {
            ans+=100;
        }
    }
    cout<<ans;
    return 0;
}
