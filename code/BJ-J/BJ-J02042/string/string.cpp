#include<bits/stdc++.h>
using namespace std;
long long n,s,ans;
struct node{
    long long num;
    char ch;
};
node a[200010];
vector<node> v;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i].num>>a[i].ch;
        s+=a[i].num;
    }
    long long l=1,r=n;
    for(long long i=1;i<=n&&l<r;i++,l++){
        long long k=a[l].num;
        while(a[r].num<k){
            k-=a[r].num;
            if(a[r].ch!=a[l].ch){
                ans+=a[r].num;
            }
            r--;
        }
        a[r].num-=k;
        if(a[r].ch!=a[l].ch)ans+=k;
        if(l==r&&l!=ceil(n/2.0)){
            cout<<ans+a[r].num-1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
