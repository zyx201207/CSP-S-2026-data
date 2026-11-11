#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[n];
    char c[n];
    string s="";
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        cin>>c[i];
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    string h="";
    for(int i=s.size()-1;i>=0;i--){
        h+=s[i];
    }
    long long m=0;
    if(s==h){
        cout<<'0';
        return 0;
    }
    else{
        for(int i=0;i<s.size()/2;i++){
            if(h[i]!=s[i]){
                m++;
            }
        }
    }
    cout<<m;
    return 0;
}

