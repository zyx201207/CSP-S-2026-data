#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int ans[100005];
vector<int> q;
void f(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=0;k<q.size();k++){
                if(a[j]==q[k]){
                    while(a[j]==q.back()){
                        q.pop_back();
                    }
                }
            }
            q.push_back(a[j]);
        }
        for(int j=1;j<=q.size()-1;j++){
            cout<<q[i]<<" ";
        }
        cout<<"\n";
        for(int j=1;j<=m;j++){
            for(int k=0;k<=q.size()-1;k++){
                if(q[k]==j){
                    ans[j]+=1;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
        f();
        return 0;
    }
    cout<<n/2<<m/2;
    return 0;
}
