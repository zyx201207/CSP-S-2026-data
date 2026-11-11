#include <bits/stdc++.h>
using namespace std;
int n,e;
int main()
{
    int s=0;
    cin>>n;
    int a[n+1];
    char c[n+1];
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    int sw = s/2;
    for(int i = 1;i <= s;i++){
        if(c[i]-'a' != c[i+sw+(s%2)]-'a') e++;
    }
    cout<<e-1;
    return 0;
}