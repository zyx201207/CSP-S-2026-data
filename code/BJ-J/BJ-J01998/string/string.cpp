#include<bits/stdc++.h>
using namespace std;
long long n,l,sum;
string s=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int ai;
        char a;
        cin>>ai>>a;
        for(int j=1;j<=ai;j++){
            l++;
            s[l]=a;
        }
    }
    for(int i=1;i<=l/2;i++){
        if(s[i]!=s[l+1-i])sum++;
    }
    cout<<sum;
    return 0;
}
