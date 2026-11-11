#include <bits/stdc++.h>
using namespace std;

long long a[10005],b[10005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2||s1!=s2)  {cout<<"0000";}
    for(int i=0;i<3;i++){
            for(int j=0;j<c2.size();j++){
                a[i]=c2[i];
                b[i]=s2[i];
            }
        if(c1==s1){
            cout<<"1";
            if(a[0]==b[0]&&a[1]==b[1]){
                cout<<"1";
                if((a[2]=='C'&&b[2]=='D')||(a[2]=='D'&&b[2]=='C')){
                    cout<<"0";
                    if(abs(a[2]-b[2])==1){
                        cout<<"1";
                        }
                    else {cout<<"0";}
                }
                else {cout<<"1";}
            }
            else {cout<<"0";}
        }
        else {cout<<"0";}
    }
    return 0;
}
