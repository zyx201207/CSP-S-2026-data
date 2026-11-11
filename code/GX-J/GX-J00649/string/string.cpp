#include<bits/stdc++.h>
using namespace std;
int n,mid,maxn=-1,ans,r,l,all;
string si="saiyu";
bool huiwen(string s){
    int r=0,l=s.size();
    while(r!=l){
        if(s[r]!=s[l])return 0;
        r++;l--;
    }
    return 1;
}
struct num{
    int id;
    char s;
}a[2001000];
char c;
int w;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].id>>a[i].s;
        si[i-1]=a[i].s;
        mid+=a[i].id;
        if(maxn<a[i].id){
            maxn=a[i].id;
            c=a[i].s;
            w=i;
        }
    }
    if(huiwen(si)==1){
        cout<<0;
        return 0;
    }
    all=mid;
    mid=(mid+1)/2;
    for(int i=1;i<=w-1;i++){
        maxn+=a[i].id;
    }
    if(maxn-mid>a[w].id/2){
        for(int i=w;i<=n;i++){
            ans+=a[i].id;
            r+=a[i].id;
        }
        for(int i=1;i<w;i++){
            l+=a[i].id;
        }
        if(l==r){
            cout<<ans;
            return 0;
        }
        else{
            ans+=r-l;
        }
    }
    else if(maxn-mid<a[w].id/2){
        for(int i=w;i<=n;i++){
            ans+=a[i].id;
            l+=a[i].id;
        }
        for(int i=1;i<w;i++){
            r+=a[i].id;
        }
        if(l==r){
            cout<<ans;
            return 0;
        }
        else{
            ans+=l-r;
        }
    }
    else{
        ans=all-maxn;
    }
    cout<<ans;
    return 0;
}
