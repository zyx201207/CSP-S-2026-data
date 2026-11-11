#include <bits/stdc++.h>
using namespace std;
int b[1000000];
int a[1000000];
int t[1000000];
int ans[100000];
int main(){
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   long long n,m;
   cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    for(int i=1;i<=n;i++){
        for(int p=i;p<=n;p++){
            a[p]=b[p];
            t[p]=0;
        }
        for(int j=i;j<=n;j++){
            if(t[a[j]]==0){
                t[a[j]]=1;
            }
            else{
                long long cnt=j-1;
                while(a[j]!=a[cnt]){
                    a[cnt]=0;
                    cnt--;
                }
                a[cnt]=0;
            }

        }
        for(int  h=i;h<=n;h++)cout<<a[h]<<" ";
        cout<<endl;

    }
return 0;
}
