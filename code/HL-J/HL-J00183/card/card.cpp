#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100010];
    int q[100010];
    stack<int> b,c,d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        b.push(a[i]);
    }
    int aa[100010];
    do{
        for(int i=0;i<d.size();i++){
            b.push(d.top());
            d.pop();

        }
        for(int i=0;i<c.size();i++){
            b.push(c.top());
            aa[c.top()]++;
            c.pop();
        }
        while(b.empty()){
            int x=b.top();
            if(q[b.top()]!=0){
                while(c.top()!=b.top()){
                    d.push(c.top());
                    c.pop();
                }
                d.push(b.top());
                q[b.top()]=1;
                b.pop();

            }
            else{
                q[b.top()]=1;
                c.push(b.top());
                b.pop();
            }
        }
    }while(c.empty());
    for(int i=0;i<100010;i++){
        if(aa[i]!=0){
            cout<<aa[i]<<' ';
        }
    }
}
