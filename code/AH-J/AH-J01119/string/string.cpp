#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,sum=0;
    char c;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++)s=s+c;
    }
    for(int i=0;i<s.size()/2;i++){
    if(s[i]!=s[s.size()-i-1])sum++;
    }
    cout<<sum;
    return 0;
}

