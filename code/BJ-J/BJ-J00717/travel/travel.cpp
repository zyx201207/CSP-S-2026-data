#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1;
    char c2[4],s2[4];
    cin>>c1;
    for(int i=1;i<=3;i++){
        cin>>c2[i];
    }
    cin>>s1;
    for(int i=1;i<=3;i++){
        cin>>s2[i];
    }
    if(c1!=s1){
        cout<<"0000";
    }
    else{
        cout<<"1";
        if(c2[1]==s2[1]&&c2[2]==s2[2]){
            cout<<"1";
            if((c2[3]>='D'&&s2[3]<='C')||(c2[3]<='C'&&s2[3]>='D')){
                cout<<"00";
            }
            else{
                cout<<"1";
                if((c2[3]=='A'&&s2[3]=='C')||(c2[3]=='C'&&s2[3]=='A')){
                    cout<<0;
                }
                else{
                    cout<<1;
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    return 0;
}
