#include <bits/stdc++.h>
usinng namespace std;
int main()
{
    int c1,c2;
    char s1,s2; 
    cin>>c1>>c2>>s1>>s1;
    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s2[0] && s[1]==s2[1])
        {
            cout<<1;   
            if((int(s1[2])<=int('B') && int(s2[2])<=int('B'))||(int(s1[2])>=int('c') && int(s2[2])>=int ('C') ))
            {
                cout<<1;
                if(s1[2]-s2[2] == 1 || s2[2]-s1[2] ==1)
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
            cout<<00;         
        }
        else
        {
            cout<<000;
        }
    }
    else
    {
        cout<<0000;
    }
    
    return 0;
}