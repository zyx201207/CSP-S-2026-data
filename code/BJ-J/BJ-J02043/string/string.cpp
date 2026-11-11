#include <bits/stdc++.h>
using namespace std;

long long ans=0;
long long l=0;
long long n;
char ch[2000000009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;


    for(int i=1;i<=n;i++){
        long long c;
        cin>>c;
        char cc;
        cin>>cc;
        for(int j=1;j<=c;j++){

            ch[l+1]=cc;
            l++;
        }
    }
    for(int i=1;i<=l/2;i++){
        if(ch[i]!=ch[l-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
