#include<bits/stdc++.h>
using namespace std;
struct T{
    int a;
    char c;
} s[200005];
long long n,sum,ans,tot;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i].a>>s[i].c;
    for(int i=0,j=n-1;i<j;i++,j--){
        int la=s[i].a,lb=s[j].a;
        if(s[i].c!=s[j].c) ans+=min(la,lb);
        //cout<<i<<' '<<la<<' '<<j<<' '<<lb<<' '<<ans<<'\n';
        if(la>lb){
            s[i].a-=lb;
            i--;
        }
        else{
            s[j].a-=la;
            j++;
        }
        //cout<<ans;
    }
    cout<<ans;
    return 0;
}
