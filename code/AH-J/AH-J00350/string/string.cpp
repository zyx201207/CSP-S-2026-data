#include<bits/stdc++.h>
using namespace std;
struct NODE{
    long long x;
    char c;
}a[200005];
long long n,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
    }
    int l=1,r=n;
    while(l<r){
        if(a[l].x>a[r].x){
            if(a[l].c!=a[r].c){
                ans+=a[r].x;
            }
            a[l].x-=a[r].x;
            a[r].x=0;
            r--;
        }else if(a[l].x<a[r].x){
            if(a[l].c!=a[r].c){
                ans+=a[l].x;
            }
            a[r].x-=a[l].x;
            a[l].x=0;
            l++;
        }else{
            if(a[l].c!=a[r].c){
                ans+=a[l].x;
            }
            a[l].x=0;
            a[r].x=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}

