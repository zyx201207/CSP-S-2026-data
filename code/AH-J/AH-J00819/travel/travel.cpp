#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<=1;i++){
        if(s1[i]!=s2[i]){
            cout<<"1000";
            return 0;
        }
    }
    if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
        int n1=s1[2]-'A'+1,n2=s2[2]-'A'+1;
        if( abs(n1-n2)==1 ){
            cout<<"1111";
            return 0;
        }
        else{
            cout<<"1110";
            return 0;
        }
    }
    else if(s1[2]>='D' && s1[2]<='E' && s2[2]>='D' && s2[2]<='E'){
        int n1=s1[2]-'A'+1,n2=s2[2]-'A'+1;
        if( abs(n1-n2)==1 ){
            cout<<"1111";
            return 0;
        }
        else{
            cout<<"1110";
            return 0;
        }
    }
    else{
        cout<<"1100";
        return 0;
    }
    return 0;
}



