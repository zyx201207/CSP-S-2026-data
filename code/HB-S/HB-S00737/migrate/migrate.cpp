#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll c,t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        map<ll,ll> chk;
        vector<ll> ar;
        ll tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            ar.push_back(tmp);
        }
        int p1=0,p2=1;
        ll ans=0;
        int len=ar.size();
        chk[ar[1]-ar[0]]=1;
        while(p2+1<len){
            if(ar[p2]-ar[p1]<=d&&ar[p2+1]-ar[p1]>d){
                auto it=chk.begin();
                if(it->second==2)ans++;
                p2++;
                if(chk.find(ar[p2]-ar[p2-1])==chk.end()){
                    chk[ar[p2]-ar[p2-1]]=1;
                }else{
                    chk[ar[p2]-ar[p2-1]]++;
                }
            }else if(ar[p2]-ar[p1]>d){
                tmp=ar[p1+1]-ar[p1];
                chk[tmp]--;
                p1++;
            }else if(ar[p2]-ar[p1]<=d){
                p2++;
                if(chk.find(ar[p2]-ar[p2-1])==chk.end()){
                    chk[ar[p2]-ar[p2-1]]=1;
                }else{
                    chk[ar[p2]-ar[p2-1]]++;
                }
            }

        }
        cout<<ans<<"\n";
    }
}