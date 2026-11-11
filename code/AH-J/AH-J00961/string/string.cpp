#include<bits/stdc++.h>
using namespace std;
int T,sum;
struct Node{
    int n,s;char a;
}t[200005];
int in=1,ans;
char geta(int x){
    int l=0,r=in;
    while(l+1<r){
        int mid=(l+r)/2;
        if(t[mid].s>=x){
            l=mid;
        }else{
            r=mid;
        }
    }
    return t[l].a;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int n;char a;
        scanf("%d",&n);cin>>a;
        sum+=n;
        t[in++]={n,n+t[in-1].s,a};
    }
    for(int i=1;i<=sum/2;i++){
        char x=geta(i),y=geta(in-1-i);
        if(x!=y)ans++;
    }
    printf("%d",ans);
    return 0;
}
