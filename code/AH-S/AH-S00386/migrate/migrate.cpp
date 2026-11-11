#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long x=0;
    int f=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-48;
        c=getchar();
    }
    return x*f;
}
long long T,n,d,X[2000005],l[2000005],r[2000005],L[2000005],R[2000005],sum[2000005],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    T=read();
    T=read();
    while(T--){
        n=read();
        d=read();
        for(int i=1;i<=n;i++){
            X[i]=read();
            l[i]=r[i]=i;
            L[i]=R[i]=1;
        }
        for(int i=1,j=1;i<=n;i++){
            while(X[i]-X[j]>d)j++;
            l[i]=j;
        }
        for(int i=n,j=n;i>=1;i--){
            while(X[j]-X[i]>d)j--;
            r[i]=j;
        }
        for(int i=1;i<n;i++){
            int t=l[i];
            if(t==i)continue;
            long long num=l[i+1]-l[i];
            if(!num)continue;
            L[i]=L[l[i]]+num;
        }
        for(int i=n;i>=2;i--){
            int t=r[i];
            if(t==i)continue;
            long long num=r[i]-r[i-1];
            if(!num)continue;
            R[i]=R[r[i]]+num;
        }
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+R[i];
        ans=0;
        for(int i=1;i<=n-3;i++){
            int t=r[i];
            if(t-i<2)continue;
            int rr=r[t-1],ll=r[t-2];
//            if(r[t]>rr&&l[t-1]<i){
//                continue;
//            }
            if(i!=1&&r[i-1]>=t-1&&r[t]>rr){
                ans+=rr-ll;
//                cout<<"ans1"<<" "<<i<<" "<<ans<<endl;
                continue;
            }
            if(i!=1&&r[i-1]>=t-1){
                if(rr!=ll)ans+=(rr-ll-1+R[rr]);
//                cout<<"ans2"<<" "<<i<<" "<<ans<<endl;
                continue;
            }
            if(r[t]>rr){
                ans+=L[i]*(rr-ll);
//                cout<<"ans3"<<" "<<i<<" "<<ans<<endl;
                continue;
            }
//            if(l[t-1]<i){
//                if(rr!=ll)ans+=(rr-ll-1+R[rr]);
//                continue;
//            }
            if(rr!=ll)ans+=L[i]*(rr-ll-1+R[rr]);
//            cout<<"ans4"<<" "<<i<<" "<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
4 5
1 3 5 10
6 3
0 1 2 3 4 7
5 2
1 2 3 4 5
7 10
69 79 88 89 97 98 100
10 3
0 3 6 7 8 9 10 11 14 17
*/
