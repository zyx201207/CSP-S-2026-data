#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
template<typename tp> inline void cmin(tp &a,tp b){(b<a)&&(a=b);}
template<typename tp> inline void cmax(tp &a,tp b){(b>a)&&(a=b);}
template<typename tp> inline void read(tp &x){
    x=0;tp f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^48);ch=getchar();}
    x*=f;
}
template<typename tp> inline void write(tp x,char ed=' '){
    static char stk[40];
    int top=0;
    if(x<0) putchar('-'),x=-x;
    do stk[++top]=x%10+48,x=x/10; while(x);
    while(top) putchar(stk[top--]);
    putchar(ed);
}
ll work(vector<ll> &x,ll d){
    int n=x.size();
    vector<int> nxt(n);
    for(int i=n-1,j=n-1;i>=0;i--){
        while(x[j]>x[i]+d) j--;
        nxt[i]=j;
        // cerr<<i<<" "<<nxt[i]<<" "<<x[j]<<" "<<x[i]<<endl;
    }
    ll ans=0;
    for(int i=n-2;i>=0;i--){
        int lst=i,o=i,l=i,r=nxt[i];
        for(;;){
            ans+=l-o;
            // cerr<<i<<":"<<lst<<","<<o<<","<<l<<","<<r<<endl;
            if(l<=r-3){
                o=nxt[r-2];
                l=nxt[r-1];
                lst=r;
                r=nxt[r];
            }else if(l==r-2){
                if(lst<r-2){
                    o=nxt[r-2];
                }else{
                    o=r;
                }
                l=nxt[r-1];
                lst=r;
                r=nxt[r];
            }else if(l==r-1){
                if(lst<r-1){
                    l=o=nxt[r-1];
                }else{
                    l=o=r;
                }
                lst=r;
                r=nxt[r];
            }else{
                if(o<l){
                    if(lst<l-1){
                        o=nxt[l-1];
                    }else{
                        o=r;
                    }
                    l=nxt[r];
                    lst=r;
                    r=nxt[r];
                }else{
                    break;
                }
            }
        }
    }
    return ans;
}
void mian(){
    int n;
    ll d;
    read(n);
    read(d);
    vector<ll> x(n); 
    for(int i=0;i<n;i++){
        read(x[i]);
    }
    ll ans=0;
    {
        int lst=0;
        for(int i=1;i<n;i++){
            if((x[i]-x[i-1])>d){
                vector<ll> y;
                y.reserve(i-lst);
                for(int j=lst;j<i;j++){
                    y.push_back(x[j]);
                }
                ans+=work(y,d);
                lst=i;
            }
        }
        {
            vector<ll> y;
            y.reserve(n-lst+1);
            for(int j=lst;j<n;j++){
                y.push_back(x[j]);
            }
            ans+=work(y,d);
        }
    }
    write(ans,'\n');
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _c,_T;
    read(_c);
    read(_T);
    while(_T--){
        mian();
    }
    return 0;
}