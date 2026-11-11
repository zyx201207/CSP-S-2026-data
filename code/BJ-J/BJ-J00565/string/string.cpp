#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[1000010];
    int n;
    cin>>n;
    int len=0;
    int l=0;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        l+=a;
        while(a--)s[len++]=c;
    }
    int cnt=0;
    for(int i=0;i<l/2;i++){
        int j=i+l-i-1;
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
    return 0;
}
