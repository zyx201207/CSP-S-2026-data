#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long  n,a[200005];
    string c,s;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>c[i];
    for(int i=0;i<n;i++){
        for (int j=0;j<a[i];j++)
            s+=c[i];
    }
    int m=0;
    for(int i=0;i<n;i++){
        if(s[i]!=s[n])
            m=m+1;
        n--;
    }
    cout<<m;
    return 0;
}
