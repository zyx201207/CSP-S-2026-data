#include<iostream>
using namespace std;
int main()
{
    string c1,s1,c2,s2;
    freopen("tarvel.in","t","stdin");
    freopen("tarvel.out","w","stdout");
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(s1[1]==s2[1]&&s1[0]==s2[0])
    {
        cout<<1;
    }
    else{
        cout<<0;    
	}
    if(s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2)
    {
        if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s1[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
        {
            cout<<1;
        }
    }
    else{
        cout<<0;    }
    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s1[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s1[2]=='D'))
    {
        cout<<1;
    }
    else{
        cout<<0;    }
    return 0;
}
