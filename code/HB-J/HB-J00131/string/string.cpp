#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PIC pair<int,char>
#define X first
#define Y second
const int N=2e5+5;
int n;
PIC a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].X>>a[i].Y;
    int l=1,r=n,ans=0;
    while(l<r){
        if(a[l].Y==a[r].Y){
            if(a[l].X<a[r].X){
                a[r].X-=a[l].X;
                l++;
            }
            else if(a[l].X>a[r].X){
                a[l].X-=a[r].X;
                r--;
            }
            else l++,r--;
        }
        else{
            if(a[l].X<a[r].X){
                ans+=a[l].X;
                a[r].X-=a[l].X;
                l++;
            }
            else if(a[l].X>a[r].X){
                ans+=a[r].X;
                a[l].X-=a[r].X;
                r--;
            }
            else{
                ans+=a[l].X;
                l++,r--;
            }
        }
    }
    cout<<ans;
}