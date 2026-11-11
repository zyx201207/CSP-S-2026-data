#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1;
    cin>>c2;
    cin>>s1;
    cin>>s2;
    int locc,locs;
    bool jc=1,js=1;
    if(c1!=s1)
    {
        cout<<"0000"<<endl;
    }
    else
    {
        cout<<"1";
        locc=(c2[0]-'0')*10+(c2[1]-'0');
        locs=(s2[0]-'0')*10+(s2[1]-'0');
        if(locc!=locs)
        {
            cout<<"000"<<endl;
        }
        else
        {
            cout<<"1";
            if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')
               jc=0;
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
               js=0;
            if(jc!=js)
            {
                cout<<"00"<<endl;
            }
            else
            {
                cout<<"1";
                if(s2[2]==c2[2]+1||c2[2]==s2[2]+1)
                cout<<"1"<<endl;
                else
                    cout<<"0"<<endl;
            }
        }
        //cout<<locc<<" "<<locs<<endl;
    }
    //cout<<c1<<" "<<c2<<" "<<s1<<" "<<s2<<endl;
    return 0;
}
