#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+100],b[n+100],c[m+1]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int t=0;t<n;t++){
        int cnt=0;
        for(int i=t;i<n;i++){
            b[cnt++]=a[i];

            for(int j=cnt-2;j>=0;j--){
                if(b[j]==a[i]){
                    cnt=j+1;

                    break;
                }
            }

        }
        for(int i=0;i<cnt;i++){

            c[b[i]]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
