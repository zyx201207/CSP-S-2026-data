#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
bool sum,num,gay;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>ss1>>ss2;
    if (s1[0] != ss1[0] || ss1[1] != s1[1]){
        cout<<"0000";
        sum = true;
    }else{
        cout<<1;
    }
    if (!sum){
        if (s2[0] == ss2[0]&&s2[1] == ss2[1]){
            cout<<1;
        }else{
            cout<<"000";
            num = true;
        }
        if (!num){
            bool tjy = false,qzt = false,ans = true;
            if (s2[2]>='A'&&s2[2]<='C'){
                tjy = true;
            }else{
                tjy = false;
            }
            if (ss2[2]>='A'&&ss2[2]<='C'){
                qzt = true;
            }else{
                qzt = false;
            }
            if (tjy == qzt){
                cout<<1;
            }else{
                cout<<0;
                cout<<0;
                ans = false;
            }
            if (ans){
                if (ss2[2] == 'A'&&s2[2] == 'C' || ss2[2] == 'C' && s2[2] == 'A'){
                    cout<<0;
                }else{
                    cout<<1;
                }
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
