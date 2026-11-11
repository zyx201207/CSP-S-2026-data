#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int ans1=0,ans2=0,ans3=0,ans4=0;
    for(int i=0;i<c1.size();i++){
        ans1=ans1*10+(c1[i]-'0');
        ans3=ans3*10+(c2[i]-'0');
    }
    if(ans1==ans3){
        cout<<1;
        ans2=(s1[0]-'0')*10+(s1[1]-'0');
        ans4=(s2[0]-'0')*10+(s2[1]-'0');
        if(ans2==ans4){
            cout<<1;
            char ch1=s1[2],ch2=s2[2];
            bool flag=0;
            if(ch1=='A'||ch1=='B'||ch1=='C'){
                if(ch2=='A'||ch2=='B'||ch2=='C'){
                    cout<<1;
                    flag=1;
                }
            }
            if(ch1=='E'||ch1=='F'){
                if(ch2=='E'||ch2=='F'){
                    cout<<1;
                    flag=1;
                }
            }
            if(flag){
                if(ch1=='A'&&ch2=='B'||ch1=='B'&&ch2=='A'||ch1=='B'&&ch2=='A'||ch1=='C'&&ch2=='B'||ch1=='D'&&ch2=='F'||ch1=='F'&&ch2=='D'){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            if(!flag){
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}