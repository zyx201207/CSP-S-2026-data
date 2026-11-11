#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string1.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1000000000],d=0;
    char c[1000000000];
    string s;
    cin>>n;
    cout<<1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(int i=1;i<=s.size()/2;i++){
        for(int j=s.size();j>=s.size()/2;j--){
            if(s[i]!=s[j]){
                s[j]=s[i];
                d++;
            }
        }
    }
    cout<<d;
    return 0;
}
