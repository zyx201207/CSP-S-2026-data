#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<=1;i++){
        if(s1[i]!=s2[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";
    if(s2[2]<='C' && s1[2]<='C' || s2[2]>='D' && s1[2]>='D'){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(s2[2]<='C' && s1[2]<='C'){
        if(abs(s1[2]-s2[2])==1) cout<<"1";
    }else if(s2[2]>='D' && s1[2]>='D'){
        if(abs(s1[2]-s2[2])==2) cout<<"1";
    }
    else cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
