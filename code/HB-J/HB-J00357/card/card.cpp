#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[500005],v[300004]={};
    bool b[300005]={};
    stack<int>s;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int k=n;
    while(k>0){
        k--;
        for(int i=n-k;i<=n;i++){
            if(b[a[i]]==1){
                while(s.top()!=a[i]){
                    s.pop();
                }
            }
            else{
                s.push(a[i]);
                b[a[i]]=1;
            }
        }
        while(!s.empty()){
            v[s.top()]++;
            s.pop();
        }
        for(int i=1;i<=m;i++)b[i]=0;
    }
    for(int i=1;i<=m;i++){
        cout<<v[i]<<' ';
    }
    return 0;
}
