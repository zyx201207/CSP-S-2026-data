#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt,g,sum1,sum2,ans,l,r;
struct node{
    long long num,used;
    char ch;
}a[200005];
void check(long long sum){
    while(r){
        if(sum2+a[r].num-a[r].used>=sum){
            a[r].used+=sum-sum2;
            if(a[r].ch!=a[l].ch){
                ans+=sum-sum2;
            }
            sum2=sum;
            break;
        }
        sum2+=a[r].num-a[r].used;
        if(a[r].ch!=a[l].ch){
            ans+=a[r].num-a[r].used;
        }
        r--;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].ch;
        cnt+=a[i].num;
    }
    r=n;
    g=cnt/2;
    l=1;
    while(1){
        sum1+=a[l].num;
        if(sum1<g){
            check(sum1);
            l++;
        }else{
            check(g);
            break;
        }
    }
    cout<<ans;
    return 0;
}
