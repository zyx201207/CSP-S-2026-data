#include<bits/stdc++.h>
using namespace std;
long long ans=0,now1=1,now2,now3,now4;
struct d{
    long long a=1,st=0,e=0;
    char c;
}s[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    now2=n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    for(;;){
        if(now1>=now2){
            break;
        }
        if(s[now1].c!=s[now2].c){
            ans+=min(s[now1].a,s[now2].a);
        }
        if(s[now1].a<s[now2].a){
            s[now2].a-=s[now1].a;
            now1++;
        }else if(s[now1].a>s[now2].a){
            s[now1].a-=s[now2].a;
            now2--;
        }else{
            now1++;
            now2--;
        }
    }
    cout<<ans;
    return 0;
}
