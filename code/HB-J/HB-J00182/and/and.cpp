#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y = 0;
}a[200010];
bool cmp(node m,node j){
    if(j.y != m.y)return j.y < m.y;
    else return j.x < m.x;
}
bool cnp(node m,node j){
        return j.x < m.x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i].x;
    sort(a + 1,a + n + 1,cnp);
    if(m == 1) {
        cout << a[1].x;
        return 0;
    }
    else if(m == 2){
        cout << (a[1].x & a[2].x);
        return 0;
    }
    else if(m == n){
        for(int i = 2;i <= m;i ++) a[i].x = a[i].x & a[i - 1].x;
        cout << a[n].x;
        return 0;
    }
    for(int i = 1;i <= n;i ++){
        int x = a[i].x;
        while(x){
            if(x % 2 == 1)a[i].y ++;
            x /= 2;
        }
    }
    sort(a + 1,a + n + 1,cmp);
    for(int i = 2;i <= m;i ++){
        a[i].x = a[i].x & a[i - 1].x;
    }
    cout << a[m].x;
    return 0;
}
