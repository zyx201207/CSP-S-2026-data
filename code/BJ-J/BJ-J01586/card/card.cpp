#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[n];
    char c[n];
    long long l=0;
    vector<char> s;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
        for(int j=0;j<a[i];j++){
            s.push_back(c[i]);
        }
    }
    return 0;
    long long t=0;
    for(long long i=0;i<l/2;i++){
        if(s[i] != s[l-1-i]){
            t++;
        }
    }
    cout<<t;
}
