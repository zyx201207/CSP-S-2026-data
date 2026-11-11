#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c[5],a[5],b,m,n;
char s[7];
cin>>c[0]>>s[0]>>s[1];
a[0]=getchar();
cin>>c[2]>>s[3]>>s[4];
a[1]=getchar();
c[1]=(int)s[0]*10+(int)s[1];
c[3]=(int)s[3]*10+(int)s[4];
if(c[0]==c[2]){
    cout<<"1";
    if(c[1]==c[3]){
        cout<<"1";
        if((a[0]<=67&&a[1]<=67)||(a[0]>67&&a[1]>67)){
            cout<<"1";
            if(a[0]-a[1]==1||s[1]-s[0]==1){
                cout<<"1"<<"\n";
                return 0;
            }
            else if(a[0]==68&&a[1]==70){
                cout<<"1"<<"\n";
                return 0;
            }
            else{
                cout<<"0"<<"\n";
                return 0;
            }
        }
        else{
            cout<<"0"<<"0"<<"\n";
            return 0;
        }
    }
    else{
        cout<<"0"<<"0"<<"0"<<"\n";
        return 0;
    }
}
else
    cout<<"0"<<"0"<<"0"<<"0"<<"\n";

return 0;
}
