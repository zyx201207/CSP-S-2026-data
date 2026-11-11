#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll a;
    char c;
}s[200005];

ll ans,n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }

    ll i=1,j=n;
    while(i<=n&&j>=1&&i<=j){
        if(s[i].c==s[j].c){
            if(s[i].a<s[j].a){
                s[j].a-=s[i].a;
                i++;
            }
            else if(s[i].a>s[j].a){
                s[i].a-=s[j].a;
                j--;
            }
            else i++,j--;
        }
        else if(s[i].c!=s[j].c){
            ans+=min(s[i].a,s[j].a);
            if(s[i].a>s[j].a){
                s[i].a-=s[j].a;
                j--;
            }
            else if(s[i].a<s[j].a){
                s[j].a-=s[i].a;
                i++;
            }
            else i++,j--;
        }
    }

    cout<<ans;
    return 0;
}
