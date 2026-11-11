#include<iostream>
#include<stack>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500100]={},ans[500100]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int b[500100]={};
        stack<int> s;
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                while(s.top()!=a[j]){
                    b[s.top()]=0;
                    s.pop();
                }
                b[a[j]]=0;
                s.pop();
            }
            b[a[j]]=1;
            s.push(a[j]);
        }
        for(int j=1;j<=m;j++){
            if(b[j]){

                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
