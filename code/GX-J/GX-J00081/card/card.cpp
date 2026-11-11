#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e5+5;
const int maxm=3*1e5+5;
int ans[maxm],a[maxn];
int n,m;

int check(vector<int> &q,int n){
    int len=q.size();
    for(int i=1;i<=len;i++){
         if(q[i]==n) return i;
    }
    return -1;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m<=2){
        if(m==1){
            cout<<n;
            return 0;
        }else{
            int two=0,one=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1) one++;
                else two++;
            }
            two--;one--;
            if(one&&two){
                cout<<n<<' '<<n;
                return 0;
            }else if(one==0){
                cout<<n-1<<' '<<n;
                return 0;
            }else{
                cout<<n<<' '<<n-1;
                return 0;
            }

        }
    }

    for(int i=1;i<=n;i++){
        vector<int> q;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            int temp=check(q,a[j]);
            q.push_back(a[j]);
        }
        int len=q.size();
        for(int x:q){
            ans[x]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';

    return 0;
}
//good bye NangNing
