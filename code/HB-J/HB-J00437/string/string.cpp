#include<bits/stdc++.h>
using namespace std;
struct node{
    long long l,s;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    node a[200010];
    cin>>n;
    long long ll=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].c;
        a[i].s=a[i-1].s+a[i].l;
    }
    ll=a[n].s;
    long long ans=0,cha=0;
    long long j=n;
    for(int i=1;i<=n/2;i++){

        if(a[i].c==a[j].c){
            cha=abs(a[i].l-a[j].l);
            if(a[i].l>a[j].l){
                a[i].l-=cha;
                i--;
            }
            else if(a[i].l<a[j].l){
                a[j].l-=cha;
                j++;
            }
        }
        else if(a[i].c!=a[n+1-i].c){
            cha=abs(a[i].l-a[n+1-i].l);
            ans+=min(a[i].l,a[n+1-i].l);
            if(a[i].l>a[j].l){
                a[i].l-=cha;
                i--;
            }
            else if(a[i].l<a[j].l){
                a[j].l-=cha;
                j++;
            }
        }
        j--;
    }
    cout<<ans;
    return 0;
}
