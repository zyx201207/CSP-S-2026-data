#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(n+1),c(m+1);
    stack<int> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int ans=0;
        for(int i=0;i<n+1;i++){
            b[i]=0;
        }
        for(int j=i;j<=n;j++){
            s.push(a[j]);
            if(b[a[j]]){
                    s.pop();
                while(s.top()!=a[j]){
                    s.pop();
                }
            }
            b[a[j]]=1;
        }
        while(!s.empty()){
            c[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }

    return 0;
}
