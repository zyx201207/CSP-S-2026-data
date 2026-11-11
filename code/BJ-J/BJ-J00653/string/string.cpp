#include<bits/stdc++.h>
using namespace std;
int n;
int c;
long long cnt=0;
struct str{
    long long a;
    char s;
};
struct str b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        c++;
        cin >> b[c].a >> b[c].s;
        if(b[c].s == b[c-1].s){
            b[c-1].a += b[c].a;
            c--;
        }
    }
    int q=1,h=c;
    while(q < h){
        long long num = min(b[q].a, b[h].a);
        if(b[q].s != b[h].s) cnt += num;
        b[q].a -= num , b[h].a -= num;
        if(b[q].a == 0) q ++;
        if(b[h].a == 0) h --;
    }
    cout << cnt;
    return 0;
}
