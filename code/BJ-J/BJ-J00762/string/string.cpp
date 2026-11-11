#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define WZH_Local
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
int t=1;
const int N=2e5+5;
int n;
struct node{
    int num;
    char ch;
    void input(){
        cin>>num>>ch;
    }
}a[N];
long long ans;
signed main(){
    #ifndef WZH_Local
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    #endif
    //cin>>t;
    while(t--){
        cin>>n;
        For(i,1,n) a[i].input();
        int l=1,r=n;
        while(l!=r){
            if(a[l].num>=a[r].num){
                ans+=(a[l].ch!=a[r].ch)*a[r].num;
                a[l].num-=a[r].num;
                r--;
            }
            else{
                ans+=(a[l].ch!=a[r].ch)*a[l].num;
                a[r].num-=a[l].num;
                l++;
            }
        }
        cout<<ans;
    }
    return 0;
}
