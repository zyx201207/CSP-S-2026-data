#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l;
struct lennn{
    char c;
    int next,per;
}m[1008600];
string data;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        int a;char lamuda;
        cin >>a>>lamuda;
        while(a--){
            l++;
            m[l].c = lamuda;
            m[l].per = l-1;m[l-1].next = l;
        }
    }
    m[l].next = -1;m[1].per = -1;
    int ans = 0;
    int lnod = (1+l)/2,rnod = (2+l)/2;
    while(1){
        if(lnod == -1 || rnod == -1) break;
        if(m[lnod].c == m[rnod].c){
            lnod=m[lnod].per;rnod=m[rnod].next;
        }
        else{
            ans++;
            lnod=m[lnod].per;rnod=m[rnod].next;
        }
    }
    cout <<ans;
    return 0;
}
