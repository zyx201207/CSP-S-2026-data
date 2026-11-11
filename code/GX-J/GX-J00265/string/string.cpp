#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    int sum=0;
    char c;
    string s="";
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a>>c;
        s+=a*c;
    }
    int len=s.size()-1;
    for(int i=1;i<=len/2;i++){
        if(s[i]!=s[len+1-i])sum++;

    }
    cout<<sum;
    return 0;
}
