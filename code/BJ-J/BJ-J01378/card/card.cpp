#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n]={0},sum[m+1]={0},s[10010]={0};
    for(int i=0;i<n;i++)cin>>a[i];

    for(int x=0;x<n;x++){

        for(int i=0;i<n;i++)s[i]=0;
        for(int i=x,p=0;i<n;i++,p++){
            for(int r=0;r<=p;r++){
                if(s[r]==a[i]){
                    for(int f=r;f<=p;f++){
                        s[f]=0;
                    }
                    s[r]=a[i];
                    p=r;
                    break;
                }
            }
            s[p]=a[i];
        }
        for(int i=0;i<n;i++)sum[s[i]]++;



   }
   for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
    return 0;
}
