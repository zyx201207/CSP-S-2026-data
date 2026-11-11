#include<bits/stdc++.h>
using namespace std;
int a[200005],t[200005];
long long d[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        cout<<n;
        return 0;
    }
    bool flag=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        t[a[i]]++;
        if(a[i]!=a[0]){
            flag=1;
        }
    }
    if(!flag){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=m;i++){
        d[i]=d[i-1]+t[i];
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
	return 0;
}
