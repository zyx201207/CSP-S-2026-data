#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    string s;
    cin>>n;
    if(n==1){
        cout<<"0";
        return 0;
    }
    for(long long i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x>>c;
        for(long long j=1;j<=x;j++){
            s+=c;
        }
    }
    string s1=s;
    reverse(s.begin(),s.end());
    long long  l;
    long long ans=0;
    if(s.size()%2==0){
        l=s.size()/2;
    }
    else{
        l=s.size()/2+1;
    }
    for(long long i=0;i<l;i++){
        if(s[i]!=s1[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

