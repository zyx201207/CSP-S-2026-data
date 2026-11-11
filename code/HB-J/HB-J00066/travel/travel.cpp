#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string op1="ABCBDFAC";
string op2="BCBAFDCA";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;
    if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1])cout<<1;
    else cout<<0;

    int flag=0,flag2=0;
    if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){
        for(int i=0;i<8;i++){
            if(s1[2]==op1[i] && s2[2]==op2[i] && i<6){//xiang lin
                flag2=1;
                flag=1;
                break;
            }else if(s1[2]==op1[i] && s2[2]==op2[i]){
                flag=1;
            }
        }
    }
    cout<<flag<<flag2<<endl;


    return 0;
}
