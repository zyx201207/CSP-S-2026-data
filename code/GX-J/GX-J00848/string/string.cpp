#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.cpp","r",stdin);
    freopen("string.cpp","w",stdout);
    int n,ai,sum=0,d=0;
    string ci;
    string s={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ai>>ci;
        for(int j=0;j<ai;j++){
            s+=ci;
        }
    }
    d=s.size()-1;
    for(int i=1;i<=d/2;i++){
        if(s[i]!=s[d-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
