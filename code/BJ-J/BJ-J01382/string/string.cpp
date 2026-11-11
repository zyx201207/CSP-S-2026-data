#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n,l=0;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        long long x;
        cin>>x>>c;
        for(int i=0;i<x;i++)
            s+=c;
    }
    int k=0;
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])
        k++;
    cout<<k<<endl;
    return 0;
}
