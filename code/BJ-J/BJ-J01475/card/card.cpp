#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int c[500005];
int f[500005];
int sum=1;
int d=0;

int main(){

freopen("card.in","r",stdin);
freopen("card.out","w",stdout);

cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
while(sum<=n){
    for(int i=sum;i<=n;i++){
        b[i]=a[i];
        for(int j=1;j<=m;j++){
           if(b[i]==j && c[j]==1){
            for(int k=1;k<=n;k++){
                if(b[k]==b[i]){
                    for(int s=k;s<=i;s++){
                        b[s]=0;
                    }
                    break;
                }
            }
           }
           else if(b[i]==j && c[j]==0) c[j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i]==j) f[j]+=1;
        }
    }
sum++;
}

for(int i=1;i<=m;i++){
    cout<<f[i]<<" ";
}
   return 0;
}
