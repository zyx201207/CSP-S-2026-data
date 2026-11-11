#include<iostream>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000"<<endl;
    else{
        cout<<'1';
        if(s1.substr(0,2)!=s2.substr(0,2))cout<<"000"<<endl;
        else{
            cout<<'1';
            int sd1,sd2;
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')sd1=0;
            else sd1=1;
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')sd2=0;
            else sd2=1;
            if(sd1!=sd2)cout<<"00"<<endl;
            else{
                cout<<'1';
                if(s1[2]!=s2[2]+1&&s2[2]!=s1[2]+1)cout<<"0"<<endl;
                else cout<<'1'<<endl;
            }
        }
    }
    return 0;
}