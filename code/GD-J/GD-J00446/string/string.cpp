#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,ans;

struct inp{
    int a,a_rev;
    char c;
}ac[N];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>ac[i].a>>ac[i].c;
    for(int i = n;i>=1;i--) ac[i].a_rev = ac[i].a + ac[i+1].a_rev;
    for(int i = 1;i<=n;i++) ac[i].a += ac[i-1].a;
    int l = 1,r = n,cur = 0;
    while(2*cur<ac[n].a && l < r){
//    	cout<<"DEBUG "<<cur<<'\n';
        if(ac[l].a-cur < ac[r].a_rev-cur){
            ans += (ac[l].c == ac[r].c?0:ac[l].a-cur);
            cur += ac[l].a-cur;
            l++;
        }else if(ac[l].a-cur > ac[r].a_rev-cur){
            ans += (ac[l].c == ac[r].c?0:ac[r].a_rev-cur);
            cur += ac[r].a_rev-cur;
            r--;
        }else {
            ans += (ac[l].c == ac[r].c?0:ac[l].a-cur);
            cur += ac[l].a-cur;
            r--;
            l++;
        }
    }
    cout<<ans;

    return 0;
}