#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,mm,a[500001],m[300001],ans[300001];
stack<int>q;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>mm;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        memset(m,0,sizeof m);
        for(int j=i;j<=n;++j){
            if(!m[a[j]]){
				q.push(a[j]);
                m[a[j]]=j;
            }
            else{
                for(int k=m[a[j]];k<j;++k){
                    m[q.top()]=0;
                    q.pop();
                }
                m[a[j]]=j;
                q.push(a[j]);
            }
        }
        while(!q.empty()){
			// cout<<i<<' '<<q.top()<<'\n';
            ans[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=mm;++i){
        cout<<ans[i]<<' ';
    }
    return 0;
}
