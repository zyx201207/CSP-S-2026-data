#include<bits/stdc++.h>
using namespace std;
#define int long long
struct fw{
    int x;
    string y;
}a[2000005];
bool cmp(fw aa,fw bb){
    return aa.x>bb.x;
}
bool cmp0d(fw aa,fw bb){
    return aa.y>bb.y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){cin>>a[i].x;
        int op=a[i].x;
        string str="";
        while(op!=0){
            if(op%2!=0)str='1'+str;
            else str='0'+str;
            op/=2;
        }
        a[i].y=str;
    }
    if(m==1){
        sort(a,a+n,cmp);
        cout<<a[0].x;
        return 0;
    }
    if(m==n){
        int ans=a[0].x;
        for(int i=1;i<n;i++)ans&=a[i].x;
        cout<<ans;
        return 0;
    }
    sort(a,a+n,cmp0d);
    int ans=a[0].x;
    for(int i=1;i<m;i++){
        ans&=a[i].x;
    }
    cout<<ans;
    return 0;
}
