#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    long long n;
    cin>>n;
    long long a[n+1];
    char b[n+1];
    long long h=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        h+=a[i];
    }
    string s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    long long g=0;
    for(int i=0;i<s.size()/2+1;i++){
        if(s[i]!=s[s.size()-1-i]){
            g++;
        }
    }
    cout<<g<<endl;
    return 0;
}
