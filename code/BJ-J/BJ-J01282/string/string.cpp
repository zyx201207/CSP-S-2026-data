#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000000],l,r,posl,posr,minn,ans;char c[1000000],cl,cr;
int main(){
    freopen("string.in","r",stdin);freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d %c",&a[i],&c[i]);
    r=n-1;
    while(l<=r){
        if(posl<posr){
            posl+=a[l];cl=c[l];
            if(cl!=cr){
                ans+=min(posl,posr)-minn;
            }minn=min(posl,posr);l++;
        }else{
            posr+=a[r];cr=c[r];
            if(cl!=cr){
                ans+=min(posl,posr)-minn;
            }minn=min(posl,posr);r--;
        }
    }cout<<ans;
    return 0;
}