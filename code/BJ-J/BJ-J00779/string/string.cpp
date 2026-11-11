#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct aa{
    int num;
    char c;
}a[N];
int n;
int ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    //cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
        //cout<<n<<endl;
    }
    //cout<<n<<endl;
    int p1=1,p2=n,p3=a[1].num,p4=a[n].num;
    int t=0;
    while(p1<p2){
        if(a[p1].c!=a[p2].c) ans+=min(p3,p4);
        t++;
        //cout<<ans<<endl;
        int tmp=min(p3,p4);
        p3-=tmp;
        p4-=tmp;
        //cout<<p3<<" "<<p4<<endl;
        if(p3==0){
            p1++;p3=a[p1].num;
        }
        if(p4==0){
            p2--;p4=a[p2].num;
        }
        //cout<<p1<<" "<<p2<<" ";
        //cout<<ans<<" "<<t<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
