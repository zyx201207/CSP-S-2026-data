#include<bits/stdc++.h>
using namespace std;
    long long n,a[200005],m=0,ans=0;
    char s1[200005];
    string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        cin>>s1[i];
        for(long long i=1;i<=a[i];i++)s[m+i]=s1[i];
        m+=a[i];
    }
    long long mid=floor(m/2);
    for(long long i=0;i<mid;i++){
        if(s[i]!=s[m-i])ans++;
    }
    cout<<ans;
    return 0;
}

