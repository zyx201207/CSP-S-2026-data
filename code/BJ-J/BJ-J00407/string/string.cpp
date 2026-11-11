#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a=0,b;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    node s[n+1];
    long long l=0;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        s[i].b=l+1;
        l+=s[i].a;
        s[i].a+=s[i-1].a;
    }
    long long i=0,ans=0;
    int lh=1,rt=n;
    while(i<l/2){
        long long f=0,j;
        if(min(l/2,s[lh].a)<(l+1-max((l+1)/2+1,s[rt].b))){
            j=min(l/2,s[lh].a);
            f=1;
        }
        if(min(l/2,s[lh].a)>(l+1-max((l+1)/2+1,s[rt].b))){
            j=l+1-max((l+1)/2+1,s[rt].b);
            f=2;
        }
        else j=min(l/2,s[lh].a);
        if(s[lh].c!=s[rt].c){
            ans+=j-i;
        }
        i=j;
        if(!f){
            lh++;
            rt--;
        }
        else if(f==1) lh++;
        else rt--;
    }
    cout<<ans;

    return 0;
}
