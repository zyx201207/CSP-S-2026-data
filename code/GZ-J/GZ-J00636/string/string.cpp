//GZ-J00636 µË²ıª
#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,tmp;
bool b=true;
string s,ns;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>tmp>>s;
    ns=s;
    for(int i=2;i<=n;i++){
        cin>>tmp>>s;
        if(s!=ns){
            b=false;
        }
        sum+=tmp;
        ns=s;
    }
    if(b==true){
        cout<<0;
    }
    else if(b==false){
        if(sum/2==0){
            cout<<sum/2;
        }
        else if(sum/2==1){
            cout<<sum/2+1;
        }

    }

    return 0;
}
