#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,jsq=0,qq;
    string a;
    cin>>n;
    for(int i=1;i<=n;i++){
        char qqu;
        cin>>qq>>qqu;
        for(int i=1;i<=qq;i++){
            a.push_back(qqu);
        }
    }
    for(int i=0;i<a.size()/2;i++){
        if(a[i]!=a[a.size()-i-1]){
            jsq++;
        }
    }
    cout<<jsq;
    return 0;
}
