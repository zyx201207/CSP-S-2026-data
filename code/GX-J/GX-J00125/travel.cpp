#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    long long n,a;
    cin>>c1>>s1>>c2>>s2>>n>>a;
    if(c1!=s1&&c2!=s2){
        cout<<1;
    }else{
        cout<<0;
    }if(c1!=s1==n&&c2!=s2==n){
        cout<<1;
    }else{
        cout<<0;
    }if(c1!=s1==n==a&&c2!=s2==n==a){
        cout<<1;
    }else{
    cout<<0;
    }if(c1!=c2){
        cout<<1;
    }else{
        cout<<0;
    }return 0;
}
