#include<bits/stdc++.h>
using namespace std;
string s;
long long n,w,cnt=0;
int  main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        string a;
        cin>>x>>a;
        for(int j=1;j<=x;j++){
            s+=a;
        }
        w+=x;
    }
    n=w;
    if(n%2==1){
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                cnt++;
            }
        }
    }
    else{
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
