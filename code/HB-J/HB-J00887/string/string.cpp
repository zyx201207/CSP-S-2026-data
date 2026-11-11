#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
string s;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>a;
        for(int j=1;j<=k;j++){
            s+=a;
        }
    }
    for(int l=0,r=s.size()-1;l<=r;l++,r--){
        if(s[l]!=s[r]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
