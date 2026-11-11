#include <bits/stdc++.h>

using namespace std;
int n,m;
string a,b;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   cin>>n>>a>>m>>b;
   if(n!=m){
    cout<<"0000";
   }
   else{
        cout<<1;
    if(a.substr(0,2)==b.substr(0,2)){
        cout<<1;
        if((a[2]=='F'&&b[2]=='D')||(a[2]=='D'&&b[2]=='F')||(a[2]>='A'&&b[2]>='A'&&a[2]<='C'&&b[2]<='C')){
            cout<<1;
            if(abs(a[2]-b[2])==1){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<"00";
        }
    }
    else{
        cout<<"000";
    }
   }
    return 0;
}
