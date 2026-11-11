#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1;cin>>c1;
    cin>>s2;cin>>c2;
    if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout<<'1';
    }else{
        cout<<"0000";
        return 0;
    }

    if(c1[0]==c2[0] && c1[1]==c2[1]){
        cout<<'1';
    }else{
        cout<<"000";
        return 0;
    }

    if('A'<=c1[2] && c1[2]<='C'){
        if('A'<=c2[2] && c2[2]<='C'){
            cout<<'1';
            if((c1[2]=='A' && c2[2]=='C')||(c2[2]=='A' && c1[2]=='C')){            //c2[2]-1==c1[2] || c2[2]==c1[2]-1
                cout<<'0';
            }else{
                cout<<'1';
            }
        }else{
            cout<<"00";
        }
    }else if('D'<=c1[2] && c1[2]<='F'){
        if('D'<=c2[2] && c2[2]<='F'){
            cout<<"11";
        }else{
            cout<<"00";
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
