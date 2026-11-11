#include<bits/stdc++.h>
using namespace std;
long long n,b,sum,ans;
char a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>a;
        for(int j=1;j<=b;j++){
            s+=a;
            ans++;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<ans/2;i++){
        if(s[i]!=s[ans-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
