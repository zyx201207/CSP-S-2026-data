#include<bits/stdc++.h>
using namespace std;
struct node{
    long long len;
    char s;
}a[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].s;
    }
    long long l=1,r=n;
    long long ans=0;
    while(l<r){
        if(a[l].len<a[r].len&&a[r].s!=a[l].s){
            a[r].len-=a[l].len;
            ans+=a[l].len;
            l++;
        }
        else if(a[l].len>a[r].len&&a[r].s!=a[l].s){
            a[l].len-=a[r].len;
            ans+=a[r].len;
            r--;
        }
        else if(a[l].len==a[r].len&&a[r].s!=a[l].s){
            ans+=a[r].len;
            r--;l++;
        }
        else if(a[l].len>a[r].len&&a[r].s==a[l].s){
            a[l].len-=a[r].len;
            r--;
        }
        else if(a[l].len<a[r].len&&a[r].s==a[l].s){
            a[r].len-=a[l].len;
            l++;
        }
        else{
            l++;r--;
        }
    }
    cout<<ans;
    return 0;
}
