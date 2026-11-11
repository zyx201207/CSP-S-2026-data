#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#define int long long
#define gc_u getchar_unlocked
#define pc_u putchar_unlocked
const int N=5e5+5;
void read(int &res){
    res=0;
    int f=1;
    char c=gc_u();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=gc_u();
    }
    while(isdigit(c))res=(res<<1)+(res<<3)+c-48,c=gc_u();
    res*=f;
}
void write(int res){
    if(!res){
        pc_u('0');pc_u('\n');
        return ;
    }
    int cnt=0,cc[20];
    while(res){
        cc[++cnt]=res%10;
        res/=10;
    }
    while(cnt)pc_u(cc[cnt--]+48);
    pc_u('\n');
}
int n,m,a[N],p[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n;i++)read(a[i]);
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
        if(a[i]==a[i+1])continue;
        int l=1,r=i,mid,res=i;
        while(l<=r){
            int mid=l+r>>1;
            if(p[i]-p[mid-1]+m<a[i]*(i-mid+1)){
                l=mid+1;
            }else{
                res=mid;
                r=mid-1;
            }
        }
        if(p[i]-p[r-1]+m>=a[i]*(i-r+1))res=r;
        ans=std::max(ans,i-res+1);
    }
    write(ans);
}