#include<bits/stdc++.h>
using namespace std;
const int N=5*100000+5;
long long n,m;
long long ans[N];
long long v[N];
vector<long long>out;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>v[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            bool finding=false;
            long long pos;
            for(long long c=0;c<out.size();c++){
                if(out[c]==v[j]){
                    finding=true;
                    pos=c;
                    break;
                }
            }
            if(!finding){
                out.push_back(v[j]);
            }
            else{
                for(long long c=out.size()-1;c>=pos;c--){
                    out.pop_back();
                }
                out.push_back(v[j]);
            }
        }
        for(long long kk=0;kk<out.size();kk++){
            ans[out[kk]]++;
        }
        out.clear();
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
