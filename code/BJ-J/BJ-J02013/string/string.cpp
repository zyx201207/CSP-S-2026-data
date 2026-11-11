#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,f1,f2,sum,ans;
struct Node{
    int a;
    char b;
}s[N];
signed main(){
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
    }
    f1=1;
    f2=n;
    while (f1<f2){
        if (s[f1].b==s[f2].b){
            if (s[f1].a>s[f2].a){
                s[f1].a-=s[f2].a;
                f2--;
            }
            else if (s[f1].a<s[f2].a){
                s[f2].a-=s[f1].a;
                f1++;
            }
            else {
                f2--;
                f1++;
            }
        }
        else{
            if (s[f1].a>s[f2].a){
                s[f1].a-=s[f2].a;
                ans+=s[f2].a;
                f2--;
            }
            else if (s[f1].a<s[f2].a){
                s[f2].a-=s[f1].a;
                ans+=s[f1].a;
                f1++;
            }
            else {
                ans+=s[f1].a;
                f2--;
                f1++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
