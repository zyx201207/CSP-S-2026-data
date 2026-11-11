#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1;
    string s1;
    string c2;
    string s2;
    string sum;
    for(int i=0;i<10;i++){
        sum[i]='0';
    }

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        sum[0]='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            sum[1]='1';
            if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='c'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
                sum[2]='1';
                if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
                    sum[3]='1';
                }
                else{
                    sum[3]='0';
                }
            }
            else{
                sum[2]='0';
                sum[3]='0';
            }
        }
        else{
            sum[1]='0';
            sum[2]='0';
            sum[3]='0';
        }
    }
    else{
        sum[0]='0';
        sum[1]='0';
        sum[2]='0';
        sum[3]='0';
    }

    for(int i=0;i<4;i++){
        cout<<sum[i];
    }
    return 0;
}
