#include<bits/stdc++.h>
using namespace std;
#define N 200005
struct node{
    long long x;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    int temp=n,ii=0;
    while(temp!=0){
        cin>>a[ii].x>>a[ii].c;
        if(ii!=0&&a[ii-1].c==a[ii].c){
            a[ii-1].x+=a[ii].x;
        }else{
            ii++;
        }
        temp--;
    }
    if(ii==1){
        cout<<'0';
        return 0;
    }
    int mid=ii/2,l,r;
    if(ii%2==1){
        l=mid;r=mid+1;
    }else{
        l=r=mid;
    }
    long long ans=0,sheng=0;
    while(l!=0){
        if(a[l].x<a[r].x){
            a[l].x+=sheng;
        }else{
            a[r].x+=sheng;
        }
        if(a[l].c!=a[r].c){
            ans+=min(a[l].x,a[r].x);
        }
        sheng=abs(a[l].x-a[r].x);
        l--,r++;
    }
    cout<<ans;
    return 0;
}
