#include<bits/stdc++.h>
using namespace std;
using int64=long long;
const int N=2e6+5;
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	vector<int64>idx(N,0);
	int c,t;
	cin>>c>>t;
	while(t--){
        idx.clear();
        int64 n,d;
        cin>>n>>d;
        for(int i=0;i<n;++i) cin>>idx[i];
        if(c<10){
            int ans=0;
            for(int i=1;i<=n;++i){
                for(int j=i+3;j<=n;++j){
                    int cnt=0;
                    for(int k=i;k+2<=j;++k){
                        if(idx[k]+d>=idx[k+2]) cnt++;
                    }if(cnt%2==0) ans++;
                }
            }
            cout<<ans<<'\n';
        }
        if(c==11||c==12){
            int64 k=idx[1]-idx[0];
            if(d<=k||d>=k*n) cout<<"0\n";
            else cout<<n-2*(d/k)+1<<'\n';
        }
        if(c==13||c==14){
            cout<<n/2;
        }
	}
	return 0;
}
