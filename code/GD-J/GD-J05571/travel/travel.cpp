#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;
    long long a1=0;
    long long a2=0;
    long long a3=0;
    long long a4=0;
    if(c1==s1){
        a1=1;
        if(int(c2[0])*10+int(c2[1])==int(s2[0])*10+int(s2[1])){
            a2=1;
            if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||(c2[2]=='D'||c2[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
                a3=1;
                if(c2[2]=='F'||s2[2]=='F'){
                    a4=1;
                }
                else{
                    if(int(c2[2]-s2[2])==1||int(s2[2]-c2[2]==1)==1){
                        a4=1;
                    }
                }
            }
        }
    }
    cout<<a1<<a2<<a3<<a4;
    return 0;
}
