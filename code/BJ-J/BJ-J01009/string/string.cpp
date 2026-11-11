#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x;
    char y;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    long long ans=0;
    long long l=1,r=n;
    while(l<r){
        if(a[l].x>a[r].x){
            if(a[l].y!=a[r].y){
                ans+=a[r].x;
            }
            a[l].x-=a[r].x;
            a[r].x-=a[r].x;
            r--;
        }
        else if(a[l].x==a[r].x){
            if(a[l].y!=a[r].y){
                ans+=a[r].x;
            }
            a[l].x-=a[r].x;
            a[r].x-=a[r].x;
            r--;
            l++;
        }
        else if(a[l].x<a[r].x){
            if(a[l].y!=a[r].y){
                ans+=a[l].x;
            }
            a[r].x-=a[l].x;
            a[l].x-=a[l].x;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
