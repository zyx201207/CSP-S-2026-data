#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s5="",s6="";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
        s5+=s2[0],s5+=s2[1];
        s6+=s4[0],s6+=s4[1];
        if(s5==s6){
            cout<<1;
            char ch1=s2[2],ch2=s4[2];
            if(ch1=='A'||ch1=='B'||ch1=='C'){
                if(ch2=='A'||ch2=='B'||ch2=='C'){
                    cout<<1;
                    if((ch1=='C'&&ch2=='A')||(ch2=='C'&&ch1=='A'))cout<<0;
                    else cout<<1;
                }
                else cout<<0<<0;
            }
            if(ch1=='D'||ch1=='F'){
                if(ch2=='D'||ch2=='F'){
                    cout<<1;
                    if((ch1=='D'&&ch2=='F')||(ch2=='D'&&ch1=='F'))cout<<1;
                    else cout<<0;
                }
                else cout<<0<<0;
            }
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    cout<<endl;
    return 0;
}