#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5],ans[m+5]={};
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        stack<int> s;
        for(int j=i;j<=n;j++){
            for(int k=i;k<j;k++){
                if(a[k]==a[j]){
                    for(int l=k;l<j;l++){
                        s.pop();
                    }
                    break;
                }
            }
            s.push(a[j]);
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
