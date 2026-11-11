#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,R=35;
int n,m,ans;
int a[N];
vector<int> bi[R];
bool flag,vi[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int cnt=a[i],ti=0;
        while(cnt!=0){
            if(cnt%2)
                bi[ti].push_back(i);
            cnt/=2;
            ti++;
        }
    }
    for(int i=R-1;i>=0;i--){
        if(bi[i].size()<m) continue;
        if(!flag){
            flag=1;
            for(int j:bi[i])
                vi[j]=1;
            ans|=(1<<i);
        }else{
            int cnt=0,la=1;
            for(int j:bi[i])
                if(vi[j])
                    cnt++;
            if(cnt>=m) ans|=(1<<i);
            else continue;
            for(int j:bi[i]){
                for(int k=la+1;k<j;k++)
                    vi[k]=0;
                la=j;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}