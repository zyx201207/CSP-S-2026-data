#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int ans,tmp;
int a[N];
char y,c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>x>>y;
        if(y==c[tmp]){
            a[tmp]+=x;
        }else{
            a[++tmp]=x;
            c[tmp]=y;
        }
    }
    int l=1,r=tmp;
    while(l<r){
        if(c[l]==c[r]){
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else{
                l++,r--;
            }
        }else{
           if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
           }else if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
           }else{
                ans+=a[l];
                l++,r--;
           }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
