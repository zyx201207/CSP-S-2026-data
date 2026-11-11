#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ld,rd;
long long ans;
struct zfd{
    int ai;
    char c;
};
zfd s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].ai>>s[i].c;
    }
    ld=1,rd=n;
    while(ld<rd){
        if(s[ld].ai>s[rd].ai){
            if(s[ld].c!=s[rd].c) ans+=s[rd].ai;
            rd--;
            s[ld].ai-=s[rd].ai;
        }
        else if(s[ld].ai<s[rd].ai){
            if(s[ld].c!=s[rd].c) ans+=s[ld].ai;
            ld++;
            s[rd].ai-=s[ld].ai;
        }
        else{
            if(s[ld].c!=s[rd].c) ans+=s[ld].ai;
            ld++;rd--;
        }
    }
    cout<<ans;
    return 0;
}
