#include<bits/stdc++.h>
using namespace std;
struct g {
    int a;
    char b;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
        cnt+=s[i].a;
    }
    int i=1;
    for(long long l=1,r=cnt;l<r;){
        if(s[i].b!=s[n-i+1].b){
            ans+=min(s[i].a,s[n-i+1].a);
        }
        if(s[i].a<s[n-i+1].a){
            l+=min(s[i].a,s[n-i+1].a),r-=min(s[i].a,s[n-i+1].a);s[n-i+1].a-=s[i].a;i++;n++;
        }
        else if(s[i].a==s[n-i+1].a){
            l+=min(s[i].a,s[n-i+1].a),r-=min(s[i].a,s[n-i+1].a);i++;
        }
        else{
            l+=min(s[i].a,s[n-i+1].a),r-=min(s[i].a,s[n-i+1].a);s[i].a-=s[n-i+1].a;n--;
        }
    }
    cout<<ans;
    return 0;
}
