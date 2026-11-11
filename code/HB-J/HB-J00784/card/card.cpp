#include<bits/stdc++.h>
using namespace std;
stack<int> d;
int n,m,a[500005],p[300001],ans[300001],h;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(p,-1,sizeof(p));
        for(int j=i;j<=n;j++){
            if(p[a[j]]!=-1){
                for(int k=p[a[j]];k<=h;k++){
                    p[d.top()]=-1;
                    d.pop();
                }
                h=p[a[j]]-1;
            }
            d.push(a[j]);
            h++;
            p[d.top()]=h;
        }
        for(int j=i;j<=n;j++){
            ans[d.top()]++;
            d.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
