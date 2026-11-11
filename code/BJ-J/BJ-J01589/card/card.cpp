#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans[100005],l;
bool b[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    stack<int>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int l=0;l<n;l++){
        for(int i=l;i<n;i++){
            int aa=a[i];
            s.push(aa);
            if(b[aa]==1){
                s.pop();
                while(s.top()!=aa){
                    s.pop();
                }
            }
            else b[aa]=1;

        }
        while(s.empty()!=1){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
