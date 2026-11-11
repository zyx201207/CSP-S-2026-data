#include<bits/stdc++.h>
using namespace std;
long long n,ans,i=1,j;
struct p{
    long long x;
    string s;
}c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i].x>>c[i].s;
    }
    j=n;
    while(i<j){
        if(c[i].s!=c[j].s){
            ans+=min(c[i].x,c[j].x);
        }
        if(c[i].x<c[j].x){c[j].x-=c[i].x;i++;}
        else if(c[i].x>c[j].x){c[i].x-=c[j].x;j--;}
        else {i++;j--;}
    }
    cout<<ans;
    return 0;
}
