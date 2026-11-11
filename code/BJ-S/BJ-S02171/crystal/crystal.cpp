#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[500010],m,l;
ll pre,ans,now,lst;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        now=lst;
        if(i==1){
            ans=1;
            l=1;
            lst=1;
            now=1;
        }else{
            if(abs(pre-(i-l)*a[i])<=m){
                now++;
            }else{
                while(abs(pre-(i-l)*a[i])>m){
                    pre-=a[l];
                    l++;
                }
                now=i-l+1;
            }
        }
        pre+=a[i];
        lst=now;
        ans=max(ans,now);
    }
    cout<<ans;
    return 0;
}
