#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2,s3,s4;
int main ()
{
    freopen("treval.in","r",stdin);
    freopen("treval.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;

    //cout <<s2[2]<<s4[2];
    if(s1!=s3)
    {
        cout <<'0000';
        return 0;
    }
    if(s1==s3)
    {
        cout <<'1';
        if(s2[0]==s4[0]&&s2[1]==s4[1])
        {
            cout <<'1';
            if(s2[2]=='A')
            {
                if(s4[2]=='B'||s4[2]=='C')
                {
                    cout <<'1';
                    if(s4[2]=='B')
                    {
                        cout <<'1';
                        return 0;
                    }
                    else
                    {
                        cout <<'0';
                        return 0;
                    }
                }
                else
                {
                    cout <<'00';
                    return 0;
                }

            }
            if(s2[2]=='B')
            {
                     if(s4[2]=='A'||s4[2]=='C')
                {
                    cout <<'11';
                    return 0;
                }
                else
                {
                   cout <<'00';
                    return 0;
                }

            }
            if(s2[2]=='C')
            {

                if(s4[2]=='B'||s4[2]=='A')
            {
                cout <<'1';
                if(s4[2]=='B')
                {
                    cout <<'1';
                    return 0;
                }
                else
                {
                    cout <<'1';
                    return 0;
                }
            }
            else
            {
                cout <<'00';
                return 0;
            }
            }
            if(s2[2]=='D')
            {
                if(s4[2]=='F')
                {
                    cout <<'11';
                    return 0;
                }
                else
                {
                    cout <<'11';
                    return 0;
                }
            }
            if(s2[2]=='F')
            {
                if(s4[2]=='D')
            {
                cout <<'11';
                return 0;
            }
            else
            {
                cout <<'00';
                return 0;
            }
            }

      }
        else
        {
            cout <<'000';
            return 0;
            }
    }
    return 0;
}
