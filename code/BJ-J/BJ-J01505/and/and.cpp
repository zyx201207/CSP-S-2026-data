#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
struct f{
    int sum=0;
    int num=0;
}a[200005];
bool cmp(f a,f b){
    if(a.sum==b.sum){
        return a.num>b.num;
    }
    return a.sum>b.sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
    }
    for(int i=1;i<=n;i++){
        long long x=a[i].num;
        while(x){
            if(x%2==1){
                a[i].sum++;
            }
            x/=2;
        }
    }
    sort(a+1,a+n+1,cmp);
    cnt=a[1].num;
    for(int i=2;i<=m;i++){
        cnt&=a[i].num;
    }
    //cout<<a[1]<<" "<<a[2]<<" "<<a[3];
    cout<<cnt;
    return 0;
}
