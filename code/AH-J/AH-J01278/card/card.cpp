#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m,a[1005],f[1005],t[1005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int num=1;
    while(1){
        for(int i=num;i<=n;i++){
            t[a[i]]++;
            if(t[a[i]]==2){
                while(1){
                    if(s.top()==a[i]){
                        s.pop();
                        break;
                    }
                    s.pop();
                }
                t[a[i]]--;
            }
            s.push(a[i]);
        }
        while(!s.empty()){
            f[s.top()]++;
            s.pop();
        }
        memset(t,0,sizeof(t));
        if(num==n){
            break;
        }
        num++;
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<" ";
    }
    return 0;
}
