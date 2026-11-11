#include<bits/stdc++.h>
using namespace std;
struct A{
    long long l,r;
    char c;
};
A e[200010];
long long n,a,sum,x,y,id1,id2,l1,r1,l2,r2,ans;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    sum=1;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        e[i].l=sum;
        e[i].r=sum+a-1;
        e[i].c=c;
        sum=sum+a;
    }
    sum--;
    if(sum%2==0){
        x=sum/2;
        y=x+1;
    }
    else{
        x=sum/2;
        y=x+2;
    }
    for(int i=1;i<=n;i++){
        if(x>=e[i].l&&x<=e[i].r) id1=i;
        if(y>=e[i].l&&y<=e[i].r) id2=i;
    }
    l1=e[id1].l,r1=x;
    l2=y,r2=e[id2].r;
    while(l1>=1&&l1<=sum&&l2>=1&&l2<=sum&&r1>=1&&r1<=sum&&r2>=1&&r2<=sum&&id1>=1&&id1<=n&&id2>=1&&id2<=n){
        if(r1-l1<r2-l2){
            if(e[id1].c!=e[id2].c) ans+=r1-l1+1;
            l2+=(r1-l1+1);
            id1--;
            l1=e[id1].l,r1=e[id1].r;
        }
        else if(r1-l1>r2-l2){
            if(e[id1].c!=e[id2].c) ans+=r2-l2+1;
            r1-=(r2-l2+1);
            id2++;
            l2=e[id2].l,r2=e[id2].r;
        }
        else {
            if(e[id1].c!=e[id2].c) ans+=r1-l1+1;
            id1--,id2++;
            l1=e[id1].l,r1=e[id1].r;
            l2=e[id2].l,r2=e[id2].r;
        }
    }
    cout<<ans;
    return 0;
}
