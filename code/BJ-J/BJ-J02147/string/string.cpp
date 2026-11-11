#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    int n,d=0,cnt=0;
    cin>>n;
    char c[1e9];
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        char b;
        cin>>b;
        for(int j=d;j<d+a;j++){
            c[j]=b;
        }
        d+=a;
    }
    for(int i=0;i<d/2;i++){
        if(c[i]!=c[d-1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
