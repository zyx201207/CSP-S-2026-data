//GZ-J00214  赵子航  贵阳市第三中学
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]=='1' and c2[0]=='1'){
        if(c1[1]>='0' and c1[1]<='7' and c1[1]!='6' and c2[1]>='0' and c2[1]<='7' and c2[1]!='6'){
            if(c1[1]==c2[1]){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
    }
    else if(c1[0]=='0' and c2[0]=='0'){
        if(c1[1]>='2' and c1[1]<='9' and c1[1]!='1' and c2[1]>='2' and c2[1]<='9' and c2[1]!='1'){
            if(c1[1]==c2[1]){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
    }
    if(s1[0]=='1' and s2[0]=='1'){
        if(s1[1]>='0' and s2[1]<='8'){
            if(s1[1]==s2[1]){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
    }
    if(s1[0]=='0' and s2[0]=='0'){
        if(s1[1]>='1' and s2[1]<='9'){
            if(s1[1]==s2[1]){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
    }
    if(s1[2]>='A' and s1[2]<='F' and s1[2]!='E' and s2[2]>='A' and s2[2]<='F' and s1[2]!='E'){
        if(s1[2]=='A' and s2[2]=='B' or s1[2]=='B' and s2[2]=='A' or s1[2]=='B' and s2[2]=='C' or s1[2]=='C' and s2[2]=='B' or
           s1[2]=='D' and s2[2]=='F' or s1[2]=='F' and s2[2]=='C'){
            cout<<"11";
        }
        else if(s1[2]=='A' and s2[2]=='C' or s1[2]=='C' and s2[2]=='A'){
            cout<<"10";
        }
        else{
            cout<<"00";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
