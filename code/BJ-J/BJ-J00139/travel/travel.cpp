#include <bits/stdc++.h>
using namespace std;
string s1,sc1,sc2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sc1>>s1>>sc2>>s2;
    if(sc1!=sc2){
        cout<<"0000"<<endl;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
            cout<<"1111"<<endl;
            return 0;
        }else if(s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F'){
            int i=(int)s1[2];
            int j=(int)s2[2];
            if(i+1==j||i-1==j||j+1==i||j-1==i){
                cout<<"1111"<<endl;
                return 0;
            }else{
                cout<<"1110"<<endl;
                return 0;
            }
        }else{
            cout<<"1100"<<endl;
            return 0;
        }
    }else{
        cout<<"1000"<<endl;
        return 0;
    }
}