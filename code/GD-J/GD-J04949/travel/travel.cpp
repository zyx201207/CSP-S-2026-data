#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) {
        cout<<"1";
        int cnt=0;
        for(int i=0;i<3;i++){
            if(s1[i]==s2[i]){
                if(i==0) cnt++;
                if(i==1){
                    if(cnt==1){
                        cout<<"1";
                        cnt++;
                    }
                }
            }
            if(i==1 && s1[i]!=s2[i]){

            cout<<"0"<<"0"<<"0";
            return 0;
            }
            if(i==2&&cnt==2){
                if(s1[i]=='A'&&s2[i]=='B'){
                    cout<<"1"<<"1";
                    cnt++;
                }
                if(s1[i]=='A'&&s2[i]=='C'){
                    cout<<"1"<<"0";
                    cnt++;
                }
                if(s1[i]=='B'&&s2[i]=='A'){
                    cout<<"1"<<"1";
                    cnt++;
                }
                if(s1[i]=='B'&&s2[i]=='C'){
                    cout<<"1"<<"1";
                    cnt++;
                }
                if(s1[i]=='C'&&s2[i]=='B'){
                    cout<<"1"<<"1";
                    cnt++;
                }
                if(s1[i]=='C'&&s2[i]=='A'){
                    cout<<"1"<<"0";
                    cnt++;
                }
                if(s1[i]=='D'&&s2[i]=='F'){
                    cout<<"1"<<"1";
                    cnt++;
                }
                if(s1[i]=='F'&&s2[i]=='D'){
                    cout<<"1"<<"1";
                    cnt++;
                }
                if(cnt!=3) cout<<"0"<<"0";
            }
        }
    }
    else cout<<"0"<<"0"<<"0"<<"0";
    return 0;
}
