#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],t[300010],table[500010];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int s=1;
        for(int j=i;j<=n;j++){
            table[s]=a[j];
            for(int l=1;l<s;l++){
                if(table[l]==table[s]){
                    s=l;
                }
            }
            s++;
        }
        for(int i=1;i<=s;i++) t[table[i]++];
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
}
