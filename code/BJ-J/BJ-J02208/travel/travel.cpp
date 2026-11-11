#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b,c,d;
    cin>> a >> b>> c>> d;
    int q,w,e,r;
    q = 10*(int(a[0])-'0')+1*(int(a[1])-'0');
    w = 10*(int(b[0])-'0')+1*(int(b[1])-'0');
    e = 10*(int(c[0])-'0')+1*(int(c[1])-'0');
    r = 10*(int(d[0])-'0')+1*(int(d[1])-'0');
    char t,y;
    t = b[2];
    y = d[2];
    int res1 = 0,res2 = 0,res3 = 0,res4 = 0;
    res1 = (q==e);
    if(res1){
        res2 = (w==r);
        if(res2){
            res3 = -1;
            if(t<='C'&&t>='A'&&y<='C'&&y>='A'){
                res3 = 1;
            }
            else if(t<='F'&&t>='D'&&y<='F'&&y>='D'){
                res3 = 1;
            }
            else res3 = 0;

            if(res3) {
                if(t+1==y||t-1==y) res4 = 1;
            }
        }
    }
    cout<<res1<<res2<<res3<<res4;


    return 0;
}