#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int c[N];
bool isd=true;
int ans;
bool cmp(int x,int y){
    return x<y;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    c[1]=a[1];
    c[2]=a[2]-a[1];
    for(int i=3;i<=n;i++){
        c[i]=a[i]-a[i-1];
        if(c[i]!=c[i-1]){
            isd=false;
        }
    }
    if(isd==true){
        int ch=c[2];
        ans=1;
        int temp=ch;
        int cost=0;
        for(int i=n;i>=1;i--){
            cost+=temp;
            if(cost>m){
                cout << ans;
                return 0;
            }
            ans++;
            temp+=ch;
        }
        if(ans>n){
            ans=n;
        }
        cout << ans;
        return 0;
    }
    for(int i=1;i<n;i++){
        int cost=0;
        int num=1;
        for(int j=i+1;j<=n;j++){
            cost+=(j-i)*c[j];
            if(cost>m){
                ans=max(num,ans);
                break;
            }
            num++;
        }
        ans=max(num,ans);
    }
    cout << ans;
    return 0;
}
