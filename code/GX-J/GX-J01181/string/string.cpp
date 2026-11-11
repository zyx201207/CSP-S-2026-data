#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in",stin);
    freopen("string.ans",stout)
    string s;
    long long n,l,m=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string s2;
        cin>>l>>s2;
        for(long long j=m-1;j<l;j++){
            s[j]=s2;
        }
        m+=l;
        l=0;
    }
    long long k=m-(m/2+m%2);
    for(long long i=n-1;i>=k;i--){
        for(long long j=o;j<=m/2;k++){
            if(s[i]!=s[j]){
                l++;
            }
        }
    }
    cout<<l;
    return 0;
}
