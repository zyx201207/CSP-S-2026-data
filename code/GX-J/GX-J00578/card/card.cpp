#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,t=0,r;
    cin>>n>>m;
    r=n;
    for(int i=0;i<n;i++){
        cin>>a[i];}
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(int q=i;q<j;q++){
                    a[q+1]=0;
                }
            }
        }
        for(int j=1;j<=m;j++){
            t=0;
            for(int p=0;p<m;p++){
                if(a[p]==a[i]){
                    t++;
                    break;
                }
            cout<<t<<" ";
            }
    }
    a[i]=a[i+1];
    a[r]=0;
    r--;
    }
    return 0;
}
