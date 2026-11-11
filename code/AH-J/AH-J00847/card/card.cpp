#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300100];
bool v[300100];
int b[300100];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        memset(v,0,sizeof(v));
        for(int j=i;j<n;j++){
            if(!s.empty() && v[a[j]]!=0){
                while(s.top()!=a[j]){
                    s.pop();
                }
                if(s.top()==a[j])s.pop();
            }
            s.push(a[j]);
            v[a[i]]=1;
        }
        while(!s.empty()){
            b[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
