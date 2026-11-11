#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int len=s1.size();
    int num1=0;
    int num2=0;
    char t1;
    char t2;
    for(int i=0;i<len;i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            num1=num1*10+(s1[i]-'0');
        }
        else{
            t1=s1[i];
        }
    }
    for(int i=0;i<len;i++){
        if(s2[i]>='0'&&s2[i]<='9'){
            num2=num2*10+(s2[i]-'0');
        }
        else{
            t2=s2[i];
        }
    }
    if(c1==c2){
        cout<<1;
        if(num1==num2){
            cout<<1;
            if((t1=='D'&&t2=='F'||t1=='F'&&t2=='D') || ((t1=='A'&&t2=='B'||t1=='A'&&t2=='C'||t1=='B'&&t2=='C') || (t2=='A'&&t1=='B'||t2=='A'&&t1=='C'||t2=='B'&&t1=='C'))){
                cout<<1;
                if((t1=='D'&&t2=='F'||t1=='F'&&t2=='D') || ((t1=='A'&&t2=='B'||t1=='B'&&t2=='C') || (t2=='A'&&t1=='B'||t2=='B'&&t1=='C'))){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}