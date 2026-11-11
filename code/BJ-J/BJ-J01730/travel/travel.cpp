#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char a1[5],a2[5],a3[5],a4[5];
    for(int i=0;i<c1.size();i++){
        a1[i]=c1[i];
    }
    for(int i=0;i<s1.size();i++){
        a2[i]=s1[i];
    }
    for(int i=0;i<c2.size();i++){
        a3[i]=c2[i];
    }
    for(int i=0;i<s2.size();i++){
        a4[i]=s2[i];
    }
    for(int i=0;i<c1.size();i++){
        if(a1[i]!=a3[i]){
            cout<<"0000";
            return 0;
        }
    }
    for(int i=0;i<2;i++){
        if(a2[i]!=a4[i]){
            cout<<"1000";
            return 0;
        }
    }
    if((a2[2]=='D'&&a4[2]=='F')||(a2[2]=='F'&&a4[2]=='D')){
        cout<<"1111";
        return 0;
    }
    else if((a2[2]=='D'&&a4[2]!='F')||(a2[2]=='F'&&a4[2]!='D')||(a4[2]=='D'&&a2[2]!='F')||(a4[2]=='F'&&a2[2]!='D')){
        cout<<"1100";
        return 0;
    }
    if((a2[2]=='A'&&a4[2]=='B')||(a2[2]=='B'&&a4[2]=='A')||(a2[2]=='B'&&a4[2]=='C')||(a2[2]=='C'&&a4[2]=='B')){
        cout<<"1111";
        return 0;
    }
    if((a2[2]=='A'&&a4[2]=='C')||(a2[2]=='C'&&a4[2]=='A')){
        cout<<"1110";
        return 0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}


