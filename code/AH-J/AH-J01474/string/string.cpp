#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct node{
    int n;
    char a;
}a[N];
int n,cnt;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].n>>a[i].a;
    }
    int l=1,r=n;
    while(l<=r){
        if(a[l].a!=a[r].a){
            if(a[l].n>a[r].n){
                a[l].n-=a[r].n;
                cnt+=a[r].n;
                r--;
            }else if(a[l].n<a[r].n){
                a[r].n-=a[l].n;
                cnt+=a[l].n;
                l++;
            }else{
                cnt+=a[l].n;
                l++;r--;
            }
        }else{
            if(a[l].n>a[r].n){
                a[l].n-=a[r].n;
                r--;
            }else if(a[l].n<a[r].n){
                a[r].n-=a[l].n;
                l++;
            }else{
                l++;r--;
            }
        }
    }
    cout<<cnt;
    return 0;
}

