#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    if(s1!=s2)  cout<<"0000";
    else{
        if(c1[0]==c2[0]&&c1[1]==c2[1]){
            if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>'C'&&c2[2]>'C')){
                char ch1=c1[2],ch2=c2[2];
                if(ch1>ch2) swap(ch1,ch2);
                if((ch1=='A'&&ch2=='B')||(ch1=='B'&&ch2=='C')||(ch1=='D'&&ch2=='F'))    cout<<"1111";
                else    cout<<"1110";
            }
            else    cout<<"1100";
        }
        else    cout<<"1000";
    }
    return 0;
}
