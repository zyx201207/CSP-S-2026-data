#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char b;
}a[200010];
int n;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
    }
    int l=1,r=n;
    while(l<r){
        if(a[l].a>a[r].a){
            if(a[l].b==a[r].b){
                a[l].a-=a[r].a;
                r--;
            }else{
                ans+=a[r].a;
                a[l].a-=a[r].a;
                r--;
            }
        }else if(a[r].a>a[l].a){
            if(a[l].b==a[r].b){
                a[r].a-=a[l].a;
                l++;
            }else{
                ans+=a[l].a;
                a[r].a-=a[l].a;
                l++;
            }
        }else{
            if(a[l].b!=a[r].b){
                ans+=a[l].a;
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}