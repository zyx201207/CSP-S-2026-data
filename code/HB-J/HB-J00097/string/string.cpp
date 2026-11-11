#include<bits/stdc++.h>
using namespace std;
char s[200005];
int k,ans=0;
long long n,r;
int main(){
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>r;
        cin>>s[n];
        for(int j=1;j<r;j++){
            s[n+j]=s[n];
        }
        n+=r;
    }
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])ans++;
    }
    cout<<ans;
}
