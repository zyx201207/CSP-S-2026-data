#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long num1=0,num2=0;
bool flag=false,vis=false,ok=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<"1";
        ok=true;
    }
    else cout<<"0000";
    if(ok==true){
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
        vis=true;
    }
    else cout<<"0";
    if(vis==true){
        if(s1[2]=='F'||s1[2]=='D'){
            if(s2[2]=='F'||s2[2]=='D'){
                cout<<"1";
                flag=true;
            }
            else{
                cout<<"0";
            }
        }
        else if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
            if((s2[2]!='F')&&(s2[2]!='D')){
                cout<<"1";
                flag=true;
            }
            else{
                cout<<"0";
            }
        }
        if(flag==false) cout<<"0";
        else if(flag==true){
            if(s1[2]=='F'||s1[2]=='D') cout<<"1";
            else{
                if((s1[2]-s2[2])==1||(s2[2]-s1[2]==1)) cout<<"1";
                else cout<<"0";
            }
        }
    }
    else cout<<"00";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
