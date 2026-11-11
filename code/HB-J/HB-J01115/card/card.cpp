#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    stack <int> a;
    cin>>n>>m;
    int c[m+1];
    int b[n],x[m+1],ans[m+1];
    for (int i=0;i<n;i++){
        cin>>b[i];
    }
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            a.push(b[j]);
            x[b[j]]++;
            if (x[b[j]]==2){
                a.pop();
                while(a.top()==b[j]){
                    a.pop();
                }
                x[b[j]]=1;
            }
        }
        int w=a.size;
        for (int q=0;q<a.size();q++){
            ans[a.top()]++;
            c[q]=a.top;
            a.pop();
        }
        for (int k=w-1;k>=0;k--){
            a.push(c[k]);
        }
    }
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
