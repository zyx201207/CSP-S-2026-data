#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
queue<int> s;
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            for(int k = i;k < j;k++){
                if(a[k] == a[j]){
                    for(int l = k;l < j;l++){
                        s.pop();
                    }
                }
            }
            s.push(a[j]);
        }
        while(!s.empty()){
            ans[s.front()]++;
            s.pop();
        }
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
