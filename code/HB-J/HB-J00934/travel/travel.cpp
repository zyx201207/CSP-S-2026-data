#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
        string s3;
        s3=s1[0];
        s3+=s1[1];
        string s4;
        s4=s2[0];
        s4+=s2[1];
        if(s3==s4) {
            cout<<"1";
            char w1=s1[2];
            char w2=s2[2];
            if((w1=='A' || w1=='B' || w1=='C') && (w2=='A' || w2=='B' || w2=='C') && w1!=w2){
                cout<<"1";
                string wz;
                wz=w1;
                wz=wz+w2;
                if(wz=="AB" || wz=="BC" || wz=="DF" || wz=="BA" || wz=="CB" || wz=="FD"){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else if((w1=='F' || w1=='D') && (w2=='F' || w2=='D') && w1!=w2){
                cout<<"1";
                string wz;
                wz=w1;
                wz=wz+w2;
                if(wz=="AB" || wz=="BC" || wz=="DF" || wz=="BA" || wz=="CB" || wz=="FD"){
                    cout<<"1";
                }
                else cout<<"0";
            }

            else{
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
