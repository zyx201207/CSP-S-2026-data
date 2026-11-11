#include<bits/stdc++.h>
#define int long long
#define pi 3.1415926
using namespace std;
int n,m;
int a[500005];
int ans[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> q;
        int cnt=-1;
        for(int j=i;j<=n;j++){
            bool flag=0;
            int num;
            for(int k=0;k<=cnt;k++){
                if(q[k]==a[j]){
                    flag=1;
                    num=k;
                    break;
                }
            }
            if(flag){
                for(int k=1;k<=cnt-num+1;k++){
                    q.pop_back();
                }
                cnt-=(cnt-num+1);
            }
            cnt++;
            q.push_back(a[j]);
        }
        int nown[300005]={};
        for(int j=0;j<=cnt;j++){
            nown[q[j]]=1;
        }
        for(int j=1;j<=m;j++){
            ans[j]+=nown[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
