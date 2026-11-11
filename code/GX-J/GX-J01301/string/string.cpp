#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,g,m=0,mb=0,s=0;
    string a,b;
    char z;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>g;
        cin>>z;
        for(int j=0;j<g;j++){
            a[m++]=z;
        }
    }
    for(int i=m-1;i>=0;i--){
        b[mb++]=a[i];
    }
    for(int i=0;i<m;i++){
        if(a[i]!=b[i]){
            s++;
        }
    }
    if(m%2==0){
        cout<<s/2;
    }
    else cout<<s;
    return 0;
}
