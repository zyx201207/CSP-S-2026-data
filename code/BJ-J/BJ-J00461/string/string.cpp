#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int x;
    char s;
}a[200005];
int n;
int ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].s;
    }
    int l=1,r=n;
    while(l<r){
        if(a[l].s!=a[r].s){
            if(a[l].x<a[r].x){
                ans+=a[l].x;
                a[r].x-=a[l].x;
                l++;
            }
            else if(a[l].x>a[r].x){
                ans+=a[r].x;
                a[l].x-=a[r].x;
                r--;
            }
            else{
                ans+=a[l].x;
                r--;
                l++;
            }
        }
        else{
            if(a[l].x<a[r].x){
                a[r].x-=a[l].x;
                l++;
            }
            else if(a[l].x>a[r].x){
                a[l].x-=a[r].x;
                r--;
            }
            else{
                r--;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
