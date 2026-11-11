#include<bits/stdc++.h>
using namespace std;
int n,m;
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n],b[n][m+1]={},c[m+1]={},d[m+1]={};
    for(int i=0;i<n;i++) cin>>a[i];
    for(int x=0;x<n;x++){
        for(int i=x;i<n;i++){
            s.push(a[i]);
            b[x][a[i]]++;
            if(b[x][a[i]]>1){
                for(int j=i;j>c[a[i]];j--) s.pop();
            }
            c[a[i]]=i;
        }
    }
     while(s.empty()==0){
            d[s.top()]++;
            s.pop();
        }
    for(int i=1;i<=m;i++) cout<<d[i]<<" ";
    return 0;
}
