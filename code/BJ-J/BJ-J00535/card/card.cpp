#include <iostream>
#include <cstdio>
#include <stack>
int a[500005],b[300005];
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    stack<int> k,l;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        while(!l.empty())l.pop();
        for(int j=i;j<=n;j++){
            bool f=0;
            for(int q=1;!k.empty();q++){
                if(k.top()==a[j])f=1;
                l.push(k.top());
                k.pop();
            }
            for(int q=1;!l.empty();q++){
                k.push(l.top());
                l.pop();
            }
            if(f){
                while(k.top()!=a[j])k.pop();
            k.pop();
            }
            k.push(a[j]);
        }
        while(!k.empty()){
            b[k.top()]++;
            k.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    return 0;
}
