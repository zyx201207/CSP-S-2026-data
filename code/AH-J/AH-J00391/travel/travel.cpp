#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    string k1=a2.substr(0,a2.size()-2);
    string k2=b2.substr(0,b2.size()-2);
    char q1=a2[a2.size()-1];
    char q2=b2[b2.size()-1];
    int sum1=a2.size();
    int sum2=b2.size();
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }
    else {
            cout<<1;
        if(a2.substr(0,sum1-1)==b2.substr(0,sum2-1)){
            cout<<1;
            if(((q1=='A'||q1=='B'||q1=='C')&&(q2=='A'||q2=='B'||q2=='C'))||((q1=='D'||q1=='F')&&(q2=='D'||q2=='F'))){
               cout<<1;
            }
            else {
                cout<<"00";
                return 0;
            }
        }
        else cout<<"00";
        if(a2[sum1-2]=='9'){
            k1="10";
        }
        else k1=k1+char(a2[sum1-2]+1);
        if(b2[sum2-2]=='9'){
            k2="10";
        }
        else k2=k2+char(b2[sum2-2]+1);
        if(q1==q2&&(k1==b2.substr(0,sum2-1)||k2==a2.substr(0,sum1-1))){
                cout<<1;
        }
        else if(b2.substr(0,sum2-1)==a2.substr(0,sum1-1)&&(char(q1+1)==q2||char(q2+1)==q1)){
            cout<<1;
        }
        else cout<<0;
    }
    return 0;
}
