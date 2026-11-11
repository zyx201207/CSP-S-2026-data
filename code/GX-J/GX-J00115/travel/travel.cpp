#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1;
    string s1;
    string c2;
    string s2;
    cin >> c1 >> s1 >>c2 >>s2;
    int cnt=0;
    if(c1[0]==c2[0]&&c1[1]==c2[1])
    {
        cout << 1;

    }
    else{
        cout << 0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
            cout << 1;

    }
    else{
        cout << 0;
    }



    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    {
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
        {


                cout <<1;

        }
        else {
            cout <<0;
        }
    }
    else if(s1[2]=='D'||s1[2]=='E')
    {
        if(s2[2]=='D'||s2[2]=='E')
        {

                cout <<1;
        }
        else {
            cout <<0;
        }

    }

    if(s1[2]=='A'&&s2[2]=='B')
    {


            cout << 1;

    }
    else if(s1[2]=='B'&&s2[2]=='A'||s2[2]=='C')
    {


            cout << 1;
    }
    else if(s1[2]=='C'&&s2[2]=='B')
    {


            cout << 1;

    }
    else if(s1[2]=='D'&&s2[2]=='E')
    {


            cout << 1;

    }
    else if(s1[2]=='E'&&s2[2]=='D')
    {


            cout << 1;

    }
    else{
        cout << 0;
    }


    return 0;
}

