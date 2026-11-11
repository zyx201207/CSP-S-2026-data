#include<bits/stdc++.h>
using namespace std;
vector<int > q;
int a[500010];
int s[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,nn;
    cin>>n>>m;
    nn=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x=0;
            for(int t=0;t<q.size();t++){
                if(q[t]==a[i]){
                    x=t;
                    break;
                }
            }
            if(x){
                for(int t=x+1;t<q.size();t++){
                    q[t]=0;
                }
            }else{
                q.push_back(a[i]);
            }
        }
        for(int j=0;j<=q.size();j++){
            s[q[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<' ';
    }
    return 0;
}

