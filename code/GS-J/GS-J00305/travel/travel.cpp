#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    long long a=s1[0];
    long long b=s1[1];
    long long c=s2[0];
    long long d=s2[1];
    long long b1=s1[2];
    long long b2=s2[2];
    if(c1==c2){
            cout<<"1";
        if((c+d)==(a+b)){
            cout<<"1";
            if(((b1-b2)<3 || (b2-b1)<3) && (b1!=67 && b2!=68)){
                cout<<"1";
                if((b1-b2)==1 || (b2-b1)==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
