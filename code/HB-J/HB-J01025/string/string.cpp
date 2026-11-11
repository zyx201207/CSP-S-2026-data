#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],p,q;
char c[maxn];
long long l=0,ans=0;
int main(){
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
//    cout<<n<<endl;;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
//        cout<<a[i]<<" "<<c[i]<<endl;
        l+=a[i];
//        cout<<"l="<<l<<endl;
    }
//    cout<<"mygo\n";
    for(long long i=1,j=l;i<=l/2;i++,j--){
        long long i1=i,j1=j;
//        cout<<i1<<":"<<j1<<endl;
        for(p=1;i1>a[p];p++)i1-=a[p];
        for(q=1;j1>a[q];q++)j1-=a[q];
//        cout<<"now->"<<i1<<"&"<<j1<<endl;
        long long o=a[p]-i1,t=j1-1;
//        cout<<o<<"^"<<t<<endl;
        if(c[p]!=c[q]){
            if(o>t){
//                cout<<"obig"<<endl;
                ans+=t;
                ans++;
                i+=t;
                j-=t;
//                cout<<"change->"<<i<<"*"<<j<<endl;
            }else{
//                cout<<"tbig"<<endl;
                ans+=o;
                ans++;
                i+=o;
                j-=o;
//                cout<<"change->"<<i<<"*"<<j<<endl;
            }
        }
//        cout<<"last->"<<i<<"*"<<j<<"!"<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
