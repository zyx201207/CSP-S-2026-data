#include<iostream>
#define int long long
using namespace std;

const int MAXN = signed(2e5)+5;

struct node{
    int l,r;
    int num;
    char c;
};

int n;
node a[MAXN];

int find_i(int x){
    int tmp = 0;
    for(int i = 1;i<=n;i++){
        if(tmp+a[i].num >= x){
            return i;
        }
        tmp += a[i].num;
    }
}

int pre_mid(int x){
    int tmp = 0;
    for(int i = 1;i<=n;i++){
        if(tmp+a[i].num >= x){
            return tmp;
        }
        tmp += a[i].num;
    }
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    // frepopen
    cin >> n;
    int sz = 0;
    for(int i = 1;i<=n;i++){
        cin >> a[i].num >> a[i].c;
        a[i].l = sz+1;
        sz += a[i].num;
        a[i].r = sz;
    }
    int mid = sz/2;
    if(sz%2)    mid++;
    // 左边和右边要相等
    // 将左边变为右边和右边变为左边是等价的
    int l = (sz%2?mid-1:mid),r = mid+1;
    int li = find_i(l),ri = find_i(r);
    int m = mid;
    int ans = 0;
    while(1<=l && r<=sz){
        int minn = min(l-a[li].l,a[ri].r-r)+1;
        l -= minn;
        r += minn;
        ans += (a[li].c!=a[ri].c)*minn;
        if(a[li].l>l)   li--;
        if(a[ri].r<r)   ri++;
        // cout << l << " " << r << " " << li << " " << ri << " " << (a[li].c!=a[ri].c)*minn << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}