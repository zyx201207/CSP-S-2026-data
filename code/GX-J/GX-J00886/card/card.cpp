#include<bits/stdc++.h>
using namespace std;

int n,m,k,b[500005]={},c[300005]={},ans[300005]={};
stack<int>a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int x;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(b[c[j]-1]){
                while(a.top()!=c[j]){
                    b[a.top()-1]=0;
                    a.pop();
                }
                a.pop();
            }
            a.push(c[j]);
            b[c[j]-1]=1;
        }
        while(!a.empty()){
            ans[a.top()-1]++;
            b[a.top()-1]=0;
            a.pop();
        }
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<" ";
    return 0;
}
