#include<bits/stdc++.h>
using namespace std;
long long a[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];

    }

    long long ans=0;
    int t=n,len=0;
    while(t--){
       long long b[300005]={},c[300005]={};
        for(int i=n-t;i<=n;i++){
            b[i]=a[i];
            c[b[i]]++;
            len++;
            if(c[a[i]]==2){
                    int j=i-1;
                while(a[j]!=a[i]){
                    j--;
                    a[j]=0;
                    len--;
                }
            }

        }
        if(len==n-t)cout<<len<<' ';
    }








    return 0;
}
