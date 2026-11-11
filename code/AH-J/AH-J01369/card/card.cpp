#include<bits/stdc++.h>
using namespace std;
stack<int> a;
int b[10001];
int coun[10001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,i,j,x,z;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>b[i];
        for(j=1;j<i;j++){
            if(b[i]==b[j]){
                for(x=j;x<=i;x++){
                    a[x]=0;
                }
                break;
            }
        }
        a.push(b[i]);
        l=a.length();
        for(z=1;z<=l;z++){
            coun[a[z]]++;
        }
    }
    for(i=1;i<=m;i++){
        cout<<coun[i];
    }
    return 0;
}
