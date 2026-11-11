#include <bits/stdc++.h>
using namespace std;
const int mx=2E5+10;
struct node{
    long long s;
    char ch;
}a[mx];
long long l,r,lz,rz,n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a[0].ch='@';
    for(int i=1;i<=n;i++){
            cin>>a[i].s>>a[i].ch;
    }
    l=1,r=n;
    lz=a[l].s,rz=a[r].s;
    while(l<=r){
        int x=min(lz,rz);
        if(a[l].ch!=a[r].ch) ans+=x;
        lz-=x,rz-=x;
        while(lz==0&&l<=r) lz=a[++l].s;
        while(rz==0&&l<=r) rz=a[--r].s;
    }
    cout<<ans;
	return 0;
}
