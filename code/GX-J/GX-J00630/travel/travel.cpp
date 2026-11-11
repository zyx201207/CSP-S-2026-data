#include<bits/stdc++.h>
using namespace std;
char c1[2], s1[3], c2[2], s2[3];
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    for(int i=0;i<2;i++)
    {
        cin>>c1[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>s1[i];
    }
    for(int i=0;i<2;i++)
    {
        cin>>c2[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>s2[i];
    }
    if((int)(c1[0]-'0')*10+(int)(c1[1]-'0')==(int)(c2[0]-'0')*10+(int)(c2[1]-'0'))
    {
        cout<<"1";
        if((int)(s1[0]-'0')*10+(int)(s1[1]-'0')==(int)(s2[0]-'0')*10+(int)(s2[1]-'0'))
        {
            cout<<"1";
            if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')
            {
                if((s2[2]=='A' || s2[2]=='B' || s2[2]=='C') && s2[2]!=s1[2])
                {
                    cout<<"1";
                    if(s1[2]=='A')
                    {
                        if(s2[2]=='B')
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
                    else if(s1[2]=='B')
                    {
                        if(s2[2]=='A' || s2[2]=='C')
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
                    else if(s1[2]=='C')
                    {
                        if(s2[2]=='B')
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
                }
                else if(s2[2]=='D' || s2[2]=='F')
                {
                    cout<<"00";
                    return 0;
                }
            }
            else if(s1[2]=='D' || s1[2]=='F')
            {
                if((s2[2]=='D' || s2[2]=='F') && s2[2]!=s1[2])
                {
                    if(s1[2]=='D')
                    {
                        if(s2[2]=='F')
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
                    else if(s1[2]=='F')
                    {
                        if(s2[2]=='D')
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
                }
                else if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
                {
                    cout<<"00";
                    return 0;
                }
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    return 0;
}
