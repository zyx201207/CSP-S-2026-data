#include<bits/stdc++.h>
using namespace std;
string s,s2;
char c[200000];
int n,a[200000],u;
int gcd(int aa,int bb){
    if(bb==0) return aa;
    else return gcd(bb,aa%bb);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    u=a[0];
    for(int i=1;i<n;i++){
        u=gcd(u,a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i]/u;j++){
            s+=c[i];
            s2=c[i]+s2;
        }
    }
    long long l=s.length();
    long long cnt=0;
    for(long long i=0;i<l;i++){
        if(s[i]!=s2[i]){
            cnt++;
        }
    }
    cout<<cnt/2*u;
    return 0;
}
