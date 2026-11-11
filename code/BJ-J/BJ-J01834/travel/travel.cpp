#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool isone=true;
    if(c1.size()!=c2.size()) isone=false;
    else for(int i=0;i<c1.size();i++) if(c1[i]!=c2[i]) isone=false;
    if(isone==false)
    {

        cout<<"0000";
        return 0;
    }
    else
    {
        bool isonerow=true;
        if(c1.size()!=c2.size()) isonerow=false;
        else
        {
            for(int i=0;i<s1.size()-1;i++) if(s1[i]!=s2[i]) isonerow=false;
        }
        if(isonerow==false)
        {
            cout<<"1000";
            return 0;
        }
        else{
            bool isonep=true;
            if((s1[s1.size()-1]-'A')>=0&&(s1[s1.size()-1]-'A')<=2)
            {
                if((s2[s2.size()-1]-'A')>=3&&(s2[s2.size()-1]-'A')<=4) isonep=false;
            }
            else if((s2[s2.size()-1]-'A')>=0&&(s2[s2.size()-1]-'A')<=2) isonep=false;
            if(isonep==false)
            {
                cout<<"1100";
            }
            else
            {
                bool isrod=true;
                if(abs((s2[s2.size()-1]-'A')-(s1[s1.size()-1]-'A'))==1) cout<<"1111";
                else cout<<"1110";
                return 0;
            }
        }
    }

}
