#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[100005],b[100005]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j++){
            b[i]=a[i];
            if(b[i]==b[j]){
                b[i]
            }
        }
    }
    return 0;
}
