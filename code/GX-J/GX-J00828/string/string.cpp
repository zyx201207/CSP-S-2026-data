#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    bool tmp=0;
    cin>>n;
    string a;

    for(int i=1;i<=n;i++){
        int x;
        string b;
        cin>>x>>b;
        for(int i=0;i<x;i++){
            a+=b[0];
        }
    }
    string f=a;
    reverse(f.begin(),f.end());
    while(a!=f){
        for(int i=0;i<a.size();i++){
            if(f[i]!=a[i]){
                f[i]=a[i];

                a[a.size()-i-1]=f[i];
                cnt++;
                break;
            }
        }

    }

    cout<<cnt;


    return 0;
}
