#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],s[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++){
        ll k=i,r=0;
        ll p[500005];
        while(k<=n){
            ll out=a[k];
            r++;
            k++;
            //cout << "this term(k="<< k-1 <<"):" << out << endl;
            if(r!=1){
                for(int i=1;i<=r;i++){
                    if(p[i]==out){
                        //cout << "have same:" << "r=" << i << endl;
                        r=i;
                    }
                }
                p[r]=out;
            }
            else p[r]=out;
        }
        for(int i=1;i<=r;i++){
            s[p[i]]++;
        }
    }
    for(int i=1;i<=m;i++) cout << s[i] << " ";
    return 0;
}
