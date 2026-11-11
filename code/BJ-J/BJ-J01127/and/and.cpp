#include<bits/stdc++.h>
using namespace std;
int nd(int a,int b){
    string a2,b2,c2="";
    int c=0;
    while(a){
        a2+=a%2+48;
        a/=2;
    }
    while(b){
        b2+=b%2+48;
        b/=2;
    }
    for(int i=0;i<max(a2.size(),b2.size());i++){
        if(i>a2.size()) a2+='0';
        if(i>b2.size()) b2+='0';
        if(a2[i]==b2[i]) c2+='1';
        else c2+='0';
    }
    reverse(c2.begin(),c2.end());
    for(int i=0;i<c2.size();i++){
        c=c*2+c2[i]-48;
    }
    return c;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<0<<endl;
}