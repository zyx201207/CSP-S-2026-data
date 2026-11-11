#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
long long mid;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        mid+=a[i];
    }
    int v=0;//中间位置的下标
    long long sum=0;
    long long x=0;
    long long res=0;
    for(int i=1;i<=n;++i){
        sum+=a[i];
        if(sum>=(mid+1)/2){
            x=(mid+1)/2-sum+a[i];
            v=i;
            break;
        }
    }
    long long cnt=0;//扩展的个数
    int l=x-(mid&1),r=a[v]-x;
    int lv=v,rv=v;
    if(l==0){
        --lv;
        l=a[lv];
    }
    if(r==0){
        ++rv;
        r=a[rv];
    }
    while(lv>=1&&rv<=n){
        if(c[lv]!=c[rv]){
            res+=min(l,r);

        }
        if(l<r){
            --lv;
            r-=l;
            l=a[lv];
        }else if(l>r){
            ++rv;
            l-=r;
            r=a[rv];
        }else{
            --lv,++rv;
            l=a[lv];
            r=a[rv];
        }
    }
    cout<<res;
    return 0;
}
