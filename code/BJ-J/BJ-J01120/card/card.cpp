#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum[300010];
stack<int> s;
bool fin(int x){
    stack<int> s1=s;
    while(!s1.empty()){
        if(s1.top()==x)return 1;
        s1.pop();
    }
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=500){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(fin(a[j])){
                    while(s.top()!=a[j])s.pop();
                    s.pop();
                }
                s.push(a[j]);
            }
            while(!s.empty()){
                sum[s.top()]++;
                s.pop();
            }
        }
        for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1])cout<<i<<" ";
        }
    }
    return 0;
}
