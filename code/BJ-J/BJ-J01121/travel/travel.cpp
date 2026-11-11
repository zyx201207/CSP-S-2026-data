#include<bits/stdc++.h>
using namespace std;
string s1,s2,z1,z2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>z1>>z2;
    if(s1==z1){
        cout<<"1";

        string sum1=s2.substr(0,2);
        string sum2=z2.substr(0,2);

        char a=s2[2],b=z2[2];
        if(sum1==sum2) cout<<"1";
        else{cout<<"000";return 0;}


        //cout<<a<<" "<<b<<endl;

        if(a>='A' && a<='C' && b>='A' && b<='C' && a!=b){
            cout<<"1";
            if(abs(a-b)==1){
                cout<<1;
            }else{
                cout<<0;
                return 0;
            }

        }else if(a>='D' && a<='F' && b>='D' && b<='F' && a!=b){
            cout<<"1";

            if(abs(a-b)==1){
                cout<<1;
            }else{
                cout<<0;
                return 0;
            }

        }else{
            cout<<"00";
            return 0;
        }

        //cout<<sum1<<" "<<sum2<<endl;
    }else{
        cout<<"0000"<<endl;
    }

  return 0;
}
