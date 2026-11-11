#include<bits/stdc++.h>
using namespace std;
const int N=2e5 + 7;
struct p{
    int m;
    char c;
}a[N],a1[N];
int n;
long long l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].m>>a[i].c;
        l+=a[i].m;
    }
    for(int i=1;i<=n;++i){
        a1[i].m=a[n-i+1].m;
        a1[i].c=a[n-i+1].c;
    }
    int cnt=1,cnt1=1;
    long long ans=0;
    for(long long i=1;i<=l/2;){
        if(a[cnt].c==a1[cnt1].c){
            if(a[cnt].m<a1[cnt1].m){
                i+=a[cnt].m;
                a1[cnt1].m-=a[cnt].m;
                a[cnt].m=0;
                ++cnt;
            }
            else{
                i+=a1[cnt1].m;
                a[cnt].m-=a1[cnt1].m;
                a1[cnt1].m=0;
                ++cnt1;
            }
        }
        else{
            if(a[cnt].m<a1[cnt1].m){
                ans+=a[cnt].m;
                i+=a[cnt].m;
                a1[cnt1].m-=a[cnt].m;
                a[cnt].m=0;
                ++cnt;
            }
            else{
                ans+=a1[cnt1].m;
                i+=a1[cnt1].m;
                a[cnt].m-=a1[cnt1].m;
                a1[cnt1].m=0;
                ++cnt1;
            }
        }
    }
    cout<<ans;
    return 0;
}