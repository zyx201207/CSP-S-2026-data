#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int N=2e6+9;
int c,t,n,d,x[N];
int cha,dcque=1,all;
int far(int id){
    int zz=upper_bound(x+1,x+1+n,x[id]+d)-x-1;
    if(zz==id) return -1;
    else return zz;
}
int low(int id){
    int zz=lower_bound(x+1,x+1+n,x[id]-d)-x;
    if(zz==id) return -1;
    return zz;
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
    c=11;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(c==11||c==12){
            int ans=0;
            int zz=far(1);
            if(zz==-1||zz==n||zz==2){
                cout<<0<<'\n';
                continue;
            }
            for(int i=zz+1;i<=n;i++){
                if(zz-low(i)==1){
                    zz=i;
                    break;
                }
            }
            cout<<n-zz+1<<'\n';
        }
        else if(c==13||c==14){
            int mid=far(1),ans=0;
            int l=1,r=mid+1;
            while(l<=n&&r<=n){
                int dis=far(l)-low(r)+1;
                if(dis==2){
                    ans++;
                    r++;
                }
                else if(dis>2) l++;
                else r++;
            }
            cout<<ans<<'\n';
        }
    }

	return 0;
}
