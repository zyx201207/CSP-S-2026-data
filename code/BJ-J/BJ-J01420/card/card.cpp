#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005]={0},t=1,b[300005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(n--){
        stack<int> s;
        for(int i=1;i<=n;i++){
            s.push(a[i]);
        }
        for(int i=t;i<=n;i++){
            while(s.top()!=a[i]){
                s.pop();
                if(s.empty()){
                    s.push(a[i]);
                    break;
                }
            }
        }
        while(!s.empty()){
            b[s.top()]++;
            cout<<s.top()<<endl;
            s.pop();
        }

    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }


    return 0;
}
