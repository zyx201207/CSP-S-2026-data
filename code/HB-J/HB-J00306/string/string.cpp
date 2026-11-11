#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    long long cnt;
    char c;
}a[200020];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].cnt >> a[i].c;
    }
    int l = 1, r = n;
    long long ans = 0;
    while(l < r){
        if(a[l].c != a[r].c){
            ans += min(a[l].cnt, a[r].cnt);
        }
        int minn = min(a[l].cnt, a[r].cnt);
        a[l].cnt -= minn;
        a[r].cnt -= minn;
        if(a[l].cnt == 0) l++;
        if(a[r].cnt == 0) r--;
    }
    cout << ans;
}
