#include<iostream>
using namespace std;
int n;
long long ans = 0;
struct node{
    long x;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i].x >> a[i].c;
    int l = 1, r = n;
    while(l < r){
        if(a[l].c != a[r].c){
            if(a[l].x > a[r].x){
                a[l].x -= a[r].x;
                ans += a[r].x;
                r--;
            }
            else if(a[l].x < a[r].x){
                a[r].x -= a[l].x;
                ans += a[l].x;
                l++;
            }
            else ans += a[l].x,l++,r--;
        }
        else{
            if(a[l].x > a[r].x){
                a[l].x -= a[r].x;
                r--;
            }
            else if(a[l].x < a[r].x){
                a[r].x -= a[l].x;
                l++;
            }
            else l++,r--;
        }
    }
    cout << ans;
    return 0;
}
