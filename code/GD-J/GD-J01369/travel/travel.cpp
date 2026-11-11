#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        int sc1=(s1[0]-'0')*10+s1[1]-'0';
        int sc2=(s2[0]-'0')*10+s2[1]-'0';
        if(sc1==sc2){
            cout<<"1";
            int a1=s1[2]-'A';
            int a2=s2[2]-'A';
            if((a1>=0&&a1<=2&&a2>=0&&a2<=2)||(a1>=3&&a1<=4&&a2>=3&&a2<=4)){
                cout<<"1";
                if(a1-a2==1||a2-a1==1)cout<<"1";
                else cout<<"0";
            }
            else {
                cout<<"00";
            }    
        }
        else cout<<"000";
        
    }
    else cout<<"0000";
    //fclose(travel.in);
    //fclose(travel.out);
    return 0;
}