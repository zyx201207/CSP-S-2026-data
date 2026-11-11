#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=6e7+5,M=2e5+5;
int t[N],a[M];
struct node{
    int num,nc=0,ch=1e9;
}c[M];
ll base[35];
bool cmp(node x,node y){
    return x.ch<y.ch;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,maxx=-1e9;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        t[a[i]]++;
    }
    base[0]=1;
    for(int i=1;i<=32;i++){
        base[i]=base[i-1]*2;
    }
    int ans=0,ma=-1e9,pos=0;
    for(int i=1;i<=maxx;i++){
        if(ma<=min(a[i],m)){
            ma=min(a[i],m);
            pos=i;
        }
    }
    if(a[pos]>=m){
        cout<<a[pos];
        return 0;
    }
    m-=a[pos];
    ans=a[pos];
    for(int i=1;i<=30;i++){
        if(a[i]-base[i]+1>0){
            if(t[a[i]-base[i]+1]){
                ans&=a[i]-base[i]+1;
                m-=t[a[i]-base[i]+1];
                if(m<=0){
                    cout<<ans;
                    return 0;
                }
            }
        }
        if(a[i]+base[i]-1<=n){
            if(t[a[i]+base[i]-1]){
                ans&=a[i]+base[i]-1;
                m-=t[a[i]+base[i]-1];
                if(m<=0){
                    cout<<ans;
                    return 0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(t[a[i]]){
            int A=a[i],su=0;
            c[i].num=A;
            while(A){
                if(A&1){
                    c[i].nc++;
                }
                A=A>>1;
                su++;
            }
            c[i].ch=su-c[i].nc;
        }
    }
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=n;i++){
        ans&=c[i].num;
        m-=t[c[i].num];
        if(m<=0){
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
