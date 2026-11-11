#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ch1,ch2;
int z1,z2;
int p1,p2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    //remove 0 for c
    if(c1[0]=='0'){
        ch1=c1[1]-'0';
    }else{
        ch1=(c1[0]-'0')*10+(c1[1]-'0');
    }
    if(c2[0]=='0'){
        ch2=c2[1]-'0';
    }else{
        ch2=(c2[0]-'0')*10+(c2[1]-'0');
    }
    //remove 0 for s
    z1=s1[2]-'A'+1;
    z2=s2[2]-'A'+1;
    if(s1[0]==0){
        p1=s1[1]-'0';
    }else{
        p1=(s1[0]-'0')*10+(s1[1]-'0');
    }
    if(s2[0]==0){
        p2=s2[1]-'0';
    }else{
        p2=(s2[0]-'0')*10+(s2[1]-'0');
    }
    //hack
    if(z1==6){
        z1--;
    }
    if(z2==6){
        z2--;
    }
    //in end
    //solve che
    if(ch1==ch2){
        cout<<1;
        //solve pai
        if(p1==p2){
            cout<<1;
            //solve tong ce
            if((z1==1&&(z2==2||z2==3))||(z1==2&&(z2==1||z2==3))||(z1==3&&(z2==1||z2==2))||(z1==4&&z2==5)||(z1==5&&z2==4)){
                cout<<1;
                //solve xianglin
                if(abs(z1-z2)==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
