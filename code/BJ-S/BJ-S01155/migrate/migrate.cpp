#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        vector<pair<int,int> > zzz;
        zzz.push_back({0,0});
        long long n,d;
        long long a[2000005];
        long long ans = 0;
        vector<int> rrr(2000005,1);
        vector<int> lll(2000005,1);
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        int l=1,r=1;
        for(l=1;l<=n;l++){
            while(a[r]-a[l] <= d && r<=n){
                r++;
            }
            zzz.push_back({l,r-1});
            if(l != r-1){
                rrr[r-1] = rrr[r-1]+rrr[l];
            }

        }
        for(int i=n-1;i>=1;i--){
            l = zzz[i].first,r = zzz[i].second;
            int ll = zzz[i+1].first,rr = zzz[i+1].second;
            if(l == r || ll == rr){
                continue;
            }
            lll[l] = lll[l]+lll[r];
        }
        for(int i=1;i<=n;i++){
            l = zzz[i].first,r = zzz[i].second;
            int ll = zzz[r-1].first,rr = zzz[r-1].second;
            if(r-l+1<2 || l+2 != r){
                continue;
            }
            for(int i=r+1;i<=rr;i++){
                ans += rrr[l]*lll[i];
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdout);
    fclose(stdin);
}
