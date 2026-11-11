#include<bits/stdc++.h>
using namespace std;
long long n,ans,l1,l2,r1,r2;
struct stu{
    int a1;
    char a2;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    stu a[n+1]={0};
    for(int i=1;i<=n;i++) cin>>a[i].a1>>a[i].a2;
    l1=1;r1=n;l2=a[1].a1;r2=a[n].a1;
    while(l1<r1){
        if(a[l1].a2!=a[r1].a2) ans+=min(l2,r2);
        if(l2<r2){
            r2=r2-l2;l1++;l2=a[l1].a1;
        }
        else if(l2>r2){
            l2=l2-r2;r1--;r2=a[r1].a1;
        }
        else{
            l1++;r1--;l2=a[l1].a1;r2=a[r1].a1;
        }
    }
    cout<<ans;
    return 0;
}
