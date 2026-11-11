#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000],b[1000000];
int ans;
int t[1000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        int t=m;
        for(int j=1;j<=n;j++){
            b[j]=a[j];
        }
        for(int j=1;j<=n;j++){
            if(t>0){
                if(b[j]!=a[i]){
                    while(b[j]<a[i]){
                        b[j]++;
                        t--;
                    }
                }
                else{
                    for(int x=1;x<=n;x++){
                        if(b[x]==a[i]) sum++;
                    }
                }
            }
            else break;
            //for(int k=1;k<=n;k++)cout<<b[k]<<" ";
        }
        sum++;
        ans=max(ans,sum);
    }
    //cout<<endl;
    cout<<ans;
    return 0;
}
