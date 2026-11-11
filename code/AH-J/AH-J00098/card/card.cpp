#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],t[300010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        stack<int> s;
        int t1[300010]={};
        for(int j=i;j<=n;j++){
            if(t1[a[j]]!=0){
                while(1){
                    int q=s.top();
                    s.pop();
                    if(q==a[j]){
                        s.push(a[j]);
                        break;
                    }t1[q]--;
                }
            }else{
                s.push(a[j]);
                t1[a[j]]++;
            }
        }while(1){
            int q=s.top();
            s.pop();
            t[q]++;
            if(s.empty()==1){
                break;
            }
        }
    }for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
