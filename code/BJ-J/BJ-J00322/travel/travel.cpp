#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[3],s1[4],c2[3],s2[4];
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
                if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                    cout<<1;
                    if(s1[2]=='B'||s2[2]=='B'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<0<<0;
                }
            }else if(s2[2]=='D'||s2[2]=='F'){
                cout<<11;
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
