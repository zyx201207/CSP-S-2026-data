#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
string s1,s2;
int len;
int ans;
struct node{
    int num;
    char z;
};
node a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin >> x >> c;
        a[i].num=x;
        a[i].z=c;
    }
    int l=1;
    int r=n;
    while(l<r){
        if(a[l].z==a[r].z){
            if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                a[r].num=0;
                r--;
            }
            else if(a[r].num>a[l].num){
                a[r].num-=a[l].num;
                a[l].num=0;
                l++;
            }
            else{
                a[r].num=0;
                a[l].num=0;
                l++;
                r--;
            }
        }
        if(a[l].z!=a[r].z){
            if(a[l].num>a[r].num){
                ans+=a[r].num;
                a[l].num-=a[r].num;
                a[r].num=0;
                r--;
            }
            else if(a[r].num>a[l].num){
                ans+=a[l].num;
                a[r].num-=a[l].num;
                a[l].num=0;
                l++;
            }
            else{
                ans+=a[l].num;
                a[r].num=0;
                a[l].num=0;
                l++;
                r--;
            }
        }
    }
    cout << ans;
    return 0;
}
