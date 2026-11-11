#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct node{
    long long x;
    char c;
}a[N];
int n, l, r;
long long ans = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
    }
    l = 1, r = n;
    while(l<r){
        if(a[l].x>=a[r].x){
            if(a[l].c != a[r].c){
                ans+=a[r].x;
            }
            a[l].x-=a[r].x;
            a[r].x = 0;
        }
        if(a[l].x<a[r].x){
            if(a[l].c != a[r].c){
                ans+=a[l].x;
            }
            a[r].x-=a[l].x;
            a[l].x = 0;
        }
        if(a[l].x == 0) l++;
        if(a[r].x==0) r--;
    }
    cout<<ans;
    return 0;
}
