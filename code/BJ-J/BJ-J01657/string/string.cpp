#include<bits/stdc++.h>
using namespace std;
int n,a;
string s,s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }

    for(int i=1;i<=n;i++){
        cin>>a>>s1;
        for(int j=1;j<=a;j++){
            s=s+s1;
        }
    }
}
