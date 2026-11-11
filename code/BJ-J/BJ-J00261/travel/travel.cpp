#include<bits/stdc++.h>
using namespace std;
const char nb1[]={' ','A','B','C'};
const char nb2[]={' ','D','F'};
string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool flag=true;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
        flag=false;
        cout<<0;
    }

    if(flag&&s1[0]==s2[0]&&s1[1]==s2[1])
        cout<<1;
    else{
        flag=false;
        cout<<0;
    }
    bool cnt=false;
    if(flag){
        for(int i=1;i<=3;i++){
            if(s1[2]==nb1[i]){
                for(int i=1;i<=3;i++){
                    if(s2[2]==nb1[i]){
                        cnt=1;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=2;i++){
            if(s1[2]==nb2[i]){
                for(int i=1;i<=2;i++){
                    if(s2[2]==nb2[i]){
                        cnt=1;
                        break;
                    }
                }
            }
        }
    }
    if(flag&&cnt){
        cout<<1;
    }else{
        flag=false;
        cout<<0;
    }

    if(flag){
        for(int i=1;i<=3;i++){
            if(s1[2]==nb1[i]&&(s2[2]==nb1[i-1]||s2[2]==nb1[i+1])){
                cout<<1;
                return 0;
            }
        }
        if((s1[2]==nb2[1]&&s2[2]==nb2[2])||(s1[2]==nb2[2]&&s2[2]==nb2[1])){
            cout<<1;
            return 0;
        }

    }
    cout<<0;
    return 0;
}