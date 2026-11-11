#include<bits/stdc++.h>
using namespace std;
int a,k,s1,l,r,f;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
    cin>>k;
    cin>>c;
    for(int j=s1;j<=s1+k;j++){
    s[j]=c;
    }
    s1+=k;
    }
    l=1;
    r=s1;
    while(l<=r){
    if(s[l]!=s[r]){
    f++;
    }
    l++,r--;
    }
    cout<<f;
    return 0;
    }
