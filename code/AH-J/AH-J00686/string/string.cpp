#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct str{
    long long a;
    char c;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    long long l=1,r=n,ans=0;
    while(l<r){
        long long minlen=min(s[l].a,s[r].a);
        if(s[l].c!=s[r].c) ans+=minlen;
        s[l].a-=minlen;
        s[r].a-=minlen;
        if(s[r].a==0) r--;
        if(s[l].a==0) l++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
