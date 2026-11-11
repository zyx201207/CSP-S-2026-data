#include<bits/stdc++.h>
using namespace std;
char s[1000000001];
int main(){
    long long n,num=0;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            num++;
            s[num]=c;
        }
    }
    long long ans=0;
    for(int i=1;i*2<=num;i++){
        if(s[i]!=s[num-i+1])
            ans++;
    }
    cout<<ans;
    return 0;
}
