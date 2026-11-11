#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        cin>>c1[i];
    }
    for(int i=1;i<=3;i++){
        cin>>s1[i];
    }
    for(int i=1;i<=2;i++){
        cin>>c2[i];
    }
    for(int i=1;i<=3;i++){
        cin>>s2[i];
    }
    if(c1[1]==c2[1]&&c1[2]==c2[2]){
        cout<<"1";
        if(s1[1]==s2[1]&&s1[2]==s2[2]){
            cout<<"1";
            if(s1[3]<='C'&&s1[3]>='A'&&s2[3]<='C'&&s2[3]>='A'){
                cout<<"1";
                if(s1[3]+1==s2[3]||s1[3]-1==s2[3]){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else if(s1[3]<='F'&&s1[3]>='D'&&s2[3]<='F'&&s2[3]>='D'){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
