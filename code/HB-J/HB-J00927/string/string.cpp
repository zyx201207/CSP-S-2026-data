#include <bits/stdc++.h>
using namespace std;
int t,i,j;
string x,y;
char b;
long long ans,n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n>>b;
        for(j=1;j<=n;j++){
            x+=b;
        }
    }
    /*for(i=x.size()-1;i>=0;i--){
        y+=x[i];
    }
    if(x.size()%2==1){
        int nb=0;
        for(i=a.size()-1;i>=a.size()/2+1;i--){
            if(x[i])
        }
    }*/
    int nb=0;
    for(i=x.size()-1;i>=0;i--){
        if(x[i]!=x[nb]){
            ans++;
        }
        nb++;
    }
    cout<<ans/2;



    return 0;
}
