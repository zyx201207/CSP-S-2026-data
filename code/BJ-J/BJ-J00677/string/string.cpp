#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
struct St{
    long long x;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
    }
    int l=0,r=n;
    long long ans=0;
    while(l<r){
        long long num=min(a[l].x,a[r].x);
        if(a[l].c != a[r].c){
            ans+=num;
        }
        a[l].x-=num;
        if(a[l].x==0){
            l++;
        }
        a[r].x-=num;
        if(a[r].x==0){
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
