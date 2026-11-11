#include<bits/stdc++.h>
using namespace std;
int a[100001],c[100001],b[100001];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            if(b[a[j]]!=0){
                memset(b,0,sizeof(b));
                b[a[j]]++;
            }
            else b[a[j]]++;
        }
        for(int j=1;j<=n;j++){
            if(b[j]!=0) c[j]++;
        }
        memset(b,0,sizeof(b));
    }
    for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
