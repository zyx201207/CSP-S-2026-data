#include<bits/stdc++.h>
using namespace std;
stack<int> t;
int n,m;
int a[5000005];
int s[3000005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
int p=n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
while(p--){
    int st=n-p;
    bool l[300005];
    for(int i=1;i<=m;i++){
        l[i]=0;
    }
    while(!t.empty()){
        t.pop();
    }
    for(int i=st;i<=n;i++){
        if(!l[a[i]]){
            t.push(a[i]);
            l[a[i]]=1;
        }else{
            while(!t.empty()&&t.top()!=a[i]){
                l[t.top()]=0;
                t.pop();
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(l[i]==1){
            s[i]++;
        }
    }
}
for(int i=1;i<=m;i++){
    cout<<s[i]<<" ";
}
return 0;
}














