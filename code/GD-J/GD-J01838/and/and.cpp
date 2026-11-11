#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
struct node{
    int a,cnt1;
    string s;
}a[2000005];

int mx;
bool f = true;

bool cmp(node x,node y){
    if(x.cnt1 != y.cnt1)return x.cnt1 > y.cnt1;
    if(x.s.size() != y.s.size())return x.s.size() > y.s.size();
    return x.a > y.a;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >> m;
    for(int i = 1;i <= n;i++){
        cin >>a[i].a;
        int x = a[i].a;
        if(a[i].a != i-1)f = false;
        while(x > 0){
            if(x % 2 == 0)a[i].s = '0' + a[i].s;
            if(x % 2 == 1)a[i].s = '1' + a[i].s,a[i].cnt1++;
            x /= 2;
        }
        mx = max(mx,a[i].a);
    }
    if(m == 1){
        cout <<mx;
        return 0;
    }
    if(f){
        ans = a[n].a;
        for(int i = n-1;i >= n-m+1;i--)ans &= a[i].a;
        cout <<ans;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    ans = a[1].a;
    for(int i = 2;i <= m;i++){
        ans = ans&a[i].a;
    }
    cout <<ans;
}
