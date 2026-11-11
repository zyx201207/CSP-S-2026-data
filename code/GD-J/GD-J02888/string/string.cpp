#include <bits/stdc++.h>
using namespace std;
struct node{
    char s;
    int a;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].s;
    long long s=0;
    int l=1,r=n;
    while(l<r){
        int x=a[l].a,y=a[r].a;
        if(a[l].s!=a[r].s){
            s+=min(x,y);
        }
        if(x==y)l++,r--;
        else if(x<y){
            l++;
            a[r].a-=x;
        }
        else{
            r--;
            a[l].a-=y;
        }
    }
    cout<<s;
    return 0;
}
