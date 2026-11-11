#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
struct node{
    long long a=0;
    char c;
}s[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        s[i].a+=s[i-1].a;
    }
    int l=1,r=s[n].a,lb=1,rb=n;
    for(int l=1;l<r;l++){
        if(s[lb].a<l){
            lb++;
        }
        if(s[rb-1].a>=r){
            rb--;
        }
        if(s[lb].c!=s[rb].c){
            ans++;
        }
        r--;
    }
    cout<<ans;
    return 0;
}
