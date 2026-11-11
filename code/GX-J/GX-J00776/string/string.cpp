#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x=0,sum=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        long long a;
        char c;
        cin>>a>>c;
        x+=a;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    for(int i=0;i<x/2;i++){
        if(s[i]!=s[x-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
