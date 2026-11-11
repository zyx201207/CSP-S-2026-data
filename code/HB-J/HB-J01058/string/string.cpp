#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
unsigned long long o=0,l,r;
char s[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    l=1,r=n;
    while(l<r){
        long long x=min(a[l],a[r]);
        if(s[l]!=s[r]) o+=x;
        if(a[l]-x==0){
            l++;
            a[r]-=x;
        }
        else if(a[r]-x==0){
            r--;
            a[l]-=x;
        }

    }
    cout<<o;

    return 0;
}

