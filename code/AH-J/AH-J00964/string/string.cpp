#include<bits/stdc++.h>
using namespace std;
struct Node{
    int s;
    char f;
};
Node a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    string s="";
    for(int i=1;i<=n;i++){
        int x;
        char c;
        scanf("%d",&x);
        cin>>c;
        a[i].s=x;
        a[i].f=c;
    }
    long long sum=0;
    int l=1,r=n,t=0;
    while(l<r){
        if(a[l].f==a[r].f){
            if(a[l].s==a[r].s){
                ++l,--r;
            }else if(a[l].s<a[r].s){
                l++;
                a[r].s-=a[l].s;
            }else {
                r--;
                a[l].s-=a[r].s;
            }
        }else{
            if(a[l].s==a[r].s){
                ++l,--r;
                sum=sum+a[l].s;
            }else if(a[l].s<a[r].s){
                l++;
                a[r].s-=a[l].s;
                sum=sum+a[l].s;
            }else {
                r--;
                a[l].s-=a[r].s;
                sum=sum+a[r].s;
            }
        }
    }
    printf("%lld",sum);
    return 0;
}
