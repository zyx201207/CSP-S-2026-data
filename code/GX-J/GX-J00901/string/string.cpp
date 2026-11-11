#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m=0,cnt=0;
    cin>>n;
    vector<long long>a(n+10);
    vector<char>c(n+10);
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        m+=a[i];

    }
    string s;
    for(int i=0;i<n;i++){
            long long t=a[i];
        while(t--){
            s+=c[i];
        }
    }
    long long x=0,y=0;
    if(m%2==0){
        for(int i=0;i<m/2;i++){
            if(s[i]!=s[m-i]) x++;
        }
        for(int i=m-1;i>=m/2;i--){
            if(s[i]!=s[m-1-i]) y++;
        }

    }else{
        for(int i=0;i<m/2;i++){
            if(s[i]!=s[m-i-1]) x++;
        }
        for(int i=m-1;i>=m/2;i--){
            if(s[i]!=s[m-i]) y++;
        }

    }
    cout<<min(x,y);
    return 0;
}
