#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long mygcd(long long x,long long y){
    if(y==0)return x;
    return mygcd(y,x%y);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    long long gcd;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(i==1)gcd=a[i];
        else gcd=mygcd(gcd,a[i]);
    }
    for(int i=1;i<=n;i++){
        a[i]/=gcd;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    long long ans=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])ans++;
    }
    cout<<ans*gcd;
    return 0;
}
