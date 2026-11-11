#include <bits/stdc++.h>
using namespace std;
string s;
char b[1000000];
long long s1,n,a[1000000],l,r;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    l=s.size();
    if(l%2==0){
        r=l/2;
    }else{
        r=l/2+1;
    }
    for(int i=1;i<=r;i++){
        if(s[i-1]!=s[l-i]){
            s1++;
        }
    }
    cout<<s1;
    return 0;
}


