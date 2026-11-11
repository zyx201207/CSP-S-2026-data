#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,t1,t2;
int side1,side2,side[7];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    t1=s2;
    t2=s4;
    t1.pop_back();
    t2.pop_back();
    if(s1==s3){
        if(t1==t2){
            if(s2[2]=='D'||s2[2]=='F'){
                side1=1;
            }
            else{
                side1=2;
            }
            if(s4[2]=='D'||s4[2]=='F'){
                side2=1;
            }
            else{
                side2=2;
            }
            if(side1==side2){
                if(side1==1){
                    cout<<"1111";
                    return 0;
                }
                else{
                    if(abs(s2[2]-s4[2])==1){
                        cout<<"1111";
                        return 0;
                    }
                    else{
                        cout<<"1110";
                        return 0;
                    }
                }
            }
            else{
                cout<<"1100";
                return 0;
            }
        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}