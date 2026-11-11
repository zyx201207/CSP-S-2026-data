#include <bits/stdc++.h>
using namespace std;
struct node{
    long long cnt; char ch;
}a[200005],frta[200005],bcka[200005];
long long top,top2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n; cin >>n;
    long long len = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].cnt >>a[i].ch;
        len += a[i].cnt;
    }
    long long frt = len/2,nw = 0;
    long long tmp = 0;
    for (int i = 1; i <= n; i++){
        if (nw && tmp == frt && (len%2)){
            a[i].cnt --;
            if (a[i].cnt == 0) continue;
        }
        if (tmp + a[i].cnt > frt && nw == 0){
            frta[++top].cnt = frt-tmp,frta[top].ch = a[i].ch;
            nw = 1;
            if (tmp + a[i].cnt-frt-(len%2) == 0) {tmp += a[i].cnt;continue;}
            bcka[++top2].cnt = tmp + a[i].cnt-frt-(len%2),bcka[top2].ch = a[i].ch;

        }
        else if (tmp + a[i].cnt == frt && nw == 0){
            frta[++top].cnt = frt-tmp,frta[top].ch = a[i].ch;
            nw = 1;
        }
        else{
            if (nw) bcka[++top2].cnt = a[i].cnt,bcka[top2].ch = a[i].ch;
            else frta[++top].cnt = a[i].cnt,frta[top].ch = a[i].ch;
        }
        tmp += a[i].cnt;
    }
/*
    for (int i = 1; i <= top; i++) cout << frta[i].cnt << " "   << "\n";
    cout << "|\n";
    for (int i = 1; i <= top2; i++) cout << bcka[i].cnt << " "   << "\n";
*/
    long long ans = 0;
    long long i = top,j = 1;
    long long cnti = 0,cntj = 0;
    while (i >= 1 && j <= top2){
        int leni = frta[i].cnt-cnti,lenj = bcka[j].cnt-cntj;
        ans += (frta[i].ch!=bcka[j].ch)*min(leni,lenj);
        if (lenj < leni){
            cntj = 0;
            j++;cnti += lenj;
        }
        if (leni < lenj){
            cnti = 0;
            i--;cntj += leni;
        }
        if (leni == lenj){
            i--,j++;cnti=cntj=0;
        }
    }
    cout << ans;
    return 0;
}
