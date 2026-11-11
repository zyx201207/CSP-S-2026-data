#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m;
int t[10000005];
int a[10000005];
void ttt(int j){
    s.push(a[j]);
    int ton[1000005]={};
    ton[a[j]]++;
    for(int i=j+1;i<=n;i++){
        if(ton[a[i]]!=0){
                ton[a[i]]--;
            while(s.top()!=a[i]){
                s.pop();
            }
        }else{
            s.push(a[j]);
            ton[a[i]]++;
        }
    }
    int t2[1000005]={};
    while(!s.empty()){
        if(t2[s.top()]!=0){
            t[s.top()]++;
            t2[s.top()]++;
            s.pop();
        }else s.pop();
    }
}
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ttt(i);
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
