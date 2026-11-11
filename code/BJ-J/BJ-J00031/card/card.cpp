#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int main(){
    freopen("card.in","w",stdin);
    freopen("card.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> s;
        stack<int> t;
        for(int j=i;j<=n;j++){
            if(s.empty()){
                s.push(a[j]);
            }else{
                bool c=0;
                while(!s.empty()){
                    if(s.top()==a[j]){
                        c=1;
                        s.pop();
                        while(!t.empty()){
                            t.pop();
                        }
                        break;
                    }
                    t.push(s.top());
                    s.pop();
                }
                if(c==0){
                    while(!t.empty()){
                        s.push(t.top());
                        t.pop();
                    }
                }
                s.push(a[j]);
            }
        }
        while(!s.empty()){
            b[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
