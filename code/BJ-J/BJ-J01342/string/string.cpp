#include<bits/stdc++.h>
using namespace std;
struct node{
    long long num,id;
    char op;
}a[1000000];
long long n,sum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i].num>>a[i].op;
        a[i].id=i;
        sum+=a[i].num;
    }
    long long done=0,mid=sum/2,r=n,ans=0;
    for(long long i=1;i<=n;i++){
        long long need=min(mid-done,a[i].num);
        done+=need;
        if(need==0||i==r){
            cout<<ans;
            return 0;
        }
        a[i].num-=need;
        while(need){
            if(need>=a[r].num){
                need-=a[r].num;
                if(a[r].op!=a[i].op) ans+=a[r].num;
                a[r].num=0;
                r--;
            }else{
                if(a[r].op!=a[i].op) ans+=need;
                a[r].num-=need;
                need=0;
                break;
            }
        }
    }
    return 0;
}
