#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans;
    cin>>c1>>s1>>c2>>s2;
    int f=1;
    for(int i=0;i<c1.size();i++){
        if(c1[i]!=c2[i]){
            f=0;
        }
    }
    if(f==0){
        cout<<"0000";
        return 0;
    }else{
        cout<<"1";
        f=1;
        for(int i=0;i<s1.size()-1;i++){
            if(s1[i]!=s2[i]){
                f=0;
            }
        }
        if(f==0){
            cout<<"000";
            return 0;
        }else{
            cout<<"1";
            f=0;
            if(s1[s1.size()-1]<'D'&&s2[s2.size()-1]<'D'){
                f=1;
            }
            if(s1[s1.size()-1]>='D'&&s2[s2.size()-1]>='D'){
                f=1;
            }
            if(f==0){
                cout<<"00";
                return 0;
            }else{
                cout<<"1";
                f=0;
                if(s1[s1.size()-1]-s2[s2.size()-1]==1){
                    f=1;
                }
                if(s2[s2.size()-1]-s1[s1.size()-1]==1){
                    f=1;
                }
                if(s2[s2.size()-1]=='D'&&s1[s1.size()-1]=='F'){
                    f=1;
                }
                if(s2[s2.size()-1]=='F'&&s1[s1.size()-1]=='D'){
                    f=1;
                }
                if(f==0){
                    cout<<"0";
                    return 0;
                }else{
                    cout<<"1";
                    return 0;
                }
            }
        }
    }
    return 0;
}
