#include<bits/stdc++.h>
using namespace std;
long long b;string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string a;
    string d;
    for(int i=0;i<n;i++){
        cin>>b;
        cin>>s;
        for(int j=0;j<b;j++){
            a+=s;
            continue;
        }
    }
    d=a;
    long long cnt=0;
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        if(a[i]!=d[i]){
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
