#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string a;
    for(int i=1;i<=n;++i){
        int ai;
        char ci;
        cin>>ai>>ci;
        for(int i=1;i<=ai;++i){
            a+=ci;
        }
    }
    string f=a.substr(0,a.size()/2);
    reverse(f.begin(),f.end());
    int cnt=0;
    for(int i=ceil(1.0*a.size()/2),j=0;i<a.size();++i,++j){
        if(f[j]!=a[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}