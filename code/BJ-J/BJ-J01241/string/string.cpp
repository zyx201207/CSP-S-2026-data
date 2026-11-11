#include<bits/stdc++.h>
using namespace std;
struct node{
    char x;
    long long s;
}a[200010];
long long sum=0,n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].x;
    }
    long long l=1,r=n;
    while(l<r){
        if(a[l].x==a[r].x){
            if(a[l].s>a[r].s){
                a[l].s-=a[r].s;
                r--;
            }else{
                a[r].s-=a[l].s;
                l++;
            }
        }else{
            if(a[l].s>a[r].s){
                sum+=a[r].s;
                a[l].s-=a[r].s;
                r--;
            }else{
                sum+=a[l].s;
                a[r].s-=a[l].s;
                l++;
            }
        }
    }
    cout<<sum;
    return 0;
}
