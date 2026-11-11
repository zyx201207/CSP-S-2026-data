#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cx=0,pai=0,ce=0,lin=0,sr,sx;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    sr=(s1[0]-'0')*10+(s1[1]-'0');
    sx=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1==c2){
        cx=1;
        if(sr==sx){
            pai=1;
            if(s1[2]>='A'&&s1[2]<='C'){
                if(s2[2]>='A'&&s2[2]<='C'){
                    ce=1;
                    if(s1[2]+s2[2]=='A'+'B'||s1[2]+s2[2]=='B'+'C'){
                        lin=1;
                    }
                }
            }
            else{
                if(s2[2]=='D'||s2[2]=='F'){
                    ce=1;
                    lin=1;
                }
            }
        }
    }
    cout<<cx<<pai<<ce<<lin;
    return 0;
}
