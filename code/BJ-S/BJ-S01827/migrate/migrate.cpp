#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e6+10,M=5010;

int c,t,n,d,x[N],v[M],f[M],s[M];
void work(){
    int ans=0;
    for(int i=1;i<=n;i++){
        f[i]=s[i]=1;
        for(int j=i-1,l1=i,l2=i;j;j--){
            while(l1>=j&&x[l1]-x[j]>d)l1--;
            if(l1<j)break;
            if(l2>l1){
                l2=l1;
                while(l2>=j&&v[l2]==v[l1])l2--;
                l2++;
            }
            v[j]=v[l1]+1;
            f[j]=s[l2]-s[l1+1];
            s[j]=s[j+1]+f[j];
            if(f[j]==2)ans++;
        }
        for(int j=1;j<=i;j++)v[j]=f[j]=s[j]=0;
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c<=10){
            work();
            continue;
        }
        if(c<=12){
            int l=d/(x[2]-x[1]);
            l*=2;
            //cout<<n<<' '<<x[2]-x[1]<<' '<<d<<'\n';
            if(l<4)cout<<"0\n";
            else cout<<max(0ll,n-l+1)<<'\n';
            continue;
        }
        if(c<=14){
            vector<int>vt;
            vt.clear();
            for(int i=1;i<=n;i++){
                if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
                    vt.push_back(i);
                }
            }
            cout<<'\n';
            if(vt.size()!=2){
                cout<<"0\n";
            }
            else{
                cout<<(vt[0]-1)*(n-vt[1])<<'\n';
            }
            continue;
        }
    }
    return 0;
}
