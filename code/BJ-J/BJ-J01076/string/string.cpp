#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,m=0;
    char c;
    string s={};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    string x={};
    for(int i=s.size()-1;i>=0;i--){
        x+=s[i];
    }
    if(x==s) cout<<0;
    else{
        for(long long i=0;i<s.size()/2;i++){
            if(s[i]!=x[i])
                m++;
            }
            cout<<m;
    }
    return 0;
}