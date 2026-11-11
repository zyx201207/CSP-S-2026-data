#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],s = 0;
string c;
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < a[i];j++){
            b += c[i];
        }
    }
    for(int i = 0;i < b.length()/2+1;i++){
        if(b[i]!=b[b.length()-i-1]){
            s++;
            b[b.length()-i+1]=b[i];
        }
    }
    cout<<s;
    return 0;
}