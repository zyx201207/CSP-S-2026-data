#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long a;
    char c;
}a[200010],b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
        b[n-i+1].a=a[i].a,b[n-i+1].c=a[i].c;
    }
    long long ans=0;
    int ai=1,bi=1;
    while(1){
        if(a[ai].c==b[bi].c){
            if(a[ai].a>b[bi].a){
                a[ai].a-b[bi].a,bi++;
            }else if(a[ai].a==b[bi].a){
                bi++,ai++;
            }else{
                b[bi].a-a[ai].a,ai++;
            }
        }else{
            if(a[ai].a>b[bi].a){
                a[ai].a-b[bi].a,ans+=b[bi].a,bi++;
            }else if(a[ai].a==b[bi].a){
                ans+=a[ai].a,bi++,ai++;
            }else{
                b[bi].a-a[ai].a,ans+=a[ai].a,ai++;
            }
        }
        if(ai==n+1||bi==n+1){
            break;
        }
    }
    cout<<ans/2;
    return 0;
}
