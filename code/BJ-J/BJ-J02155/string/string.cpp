#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s,sum=0;
    bool a=true;
    cin>>n;
    string z=" ",m;
    for(int i=1;i<=n;i++){
        cin>>s>>m;
        for(int j=0;j<s;j++){
            z+=m;
        }
    }
    for(int i=1;i<=(z.size()-1)/2;i++){
        if(z[i]!=z[z.size()-i]){
            sum++;
            a=false;
        }
    }
    if(a==true){
        cout<<0;
    }else{
        cout<<sum;
    }
    //7891
    return 0;
}
