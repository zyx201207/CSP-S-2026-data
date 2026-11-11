#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string pai1=s1.substr(0,2);
    string pai2=s2.substr(0,2);
    if (c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    else if(pai1!=pai2)
    {
        cout<<"1000";
        return 0;
    }
    else
    {
        char wei1=s1[2],wei2=s2[2];
        if ((wei1>='A'&&wei1<='C')&&(wei2>='A'&&wei2<='C'))
        {
            if (abs(wei1-wei2)==1) cout<<"1111";
            else cout<<"1110";
        }
        else if((wei1=='D'&&wei2=='F')||(wei1=='F'&&wei2=='D')) cout<<"1111";
        else cout<<"1100";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
