#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,p,ans;char q;
struct node{
    long long m;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;int cnt=0;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>p>>q;
        if(i!=1&&q==a[cnt].c){
            a[cnt].m+=p;
        }
        else{
            cnt++,a[cnt].m=p,a[cnt].c=q;
        }
    }
    if(cnt==1){
        cout<<0;
        return 0;
    }
    int l=0,r=0;
    for(int i=1;i<=cnt;i++){
        int f=a[i].m-l,g=a[cnt-i+1].m-r;
        if(i==cnt-i+1){//ji
            ans+=max(l,r);
            break;
        }
        else if(i>cnt-i-1){
            break;
        }
        else if(a[i].c==a[cnt-i+1].c){
            ans+=abs(f-g);
            l=0,r=0;
        }
        else{
            //r.c!=a[cnt-i+1].m
            ans+=min(f,g);
            if(f<g)
                l=0,r=g-f;
            else if(f==g)
                l=0,r=0;
            else
                l=f-g,r=0;
        }
    }
    cout<<ans;
    return 0;
}