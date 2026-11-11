#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long ans;
struct node{
    long long m;
    char c;
}a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].m>>a[i].c;
    }
    long long l=a[1].m,r=a[n].m;
    int cnt1=1,cnt2=n;
    char t=a[1].c,p=a[n].c;
    while(cnt1<cnt2){
        if(t!=p){
            ans+=min(l,r);
        }
        if(l==r) r=a[--cnt2].m,p=a[cnt2].c,l=a[++cnt1].m,t=a[cnt1].c;
        else if(l>r) l-=r,r=a[--cnt2].m,p=a[cnt2].c;
        else if(r>l) r-=l,l=a[++cnt1].m,t=a[cnt1].c;

    }
    cout<<ans;
   return 0;
}
