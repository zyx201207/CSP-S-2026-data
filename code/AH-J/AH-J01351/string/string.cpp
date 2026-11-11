#include<bits/stdc++.h>
using namespace std;
string fz(string a){
    string b;
    for(int i=a.size()-1;i>=0;i--){
        b+=a[i];
    }
    return b;
}
bool hw(string a){
    string b=fz(a);
    return b==a;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a="";
    int n;
    cin>>n;
    int x;
    char c;
    cin>>x>>c;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<x;i++){
        a+=c;
    }
    for(int i=1;i<n;i++){
        cin>>x>>c;
        for(int j=0;j<x;j++){
            a+=c;
        }
    }
    if(hw(a)){
         cout<<0;
         return 0;
    }
    string b=fz(a.substr(0,a.size()/2));
    int j=0,cnt=0;
    if(a.size()%2){
        for(int i=a.size()/2+1;i<a.size();i++){
            if(b[j]!=a[i]){
                cnt++;
            }
            j++;
        }
    }else{
        for(int i=a.size()/2;i<a.size();i++){
            if(b[j]!=a[i]){
                cnt++;
            }
            j++;
        }
    }
    cout<<cnt;
    return 0;
}
