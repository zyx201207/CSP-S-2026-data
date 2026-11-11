#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    frepoen("card.out","w",stdout);
    int m,n,sum=0;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=1;i<=n;i++){
        cin>>a[n];
    }
    for(i=1;i<=n;i++){
        b[i]=a[i];
        for(int j=1;j<=i;j++){
            if(b[i]==b[j]){
                for(int k=j;k<=i;k++){
                    b[k]=0;
                }
                b[j]=a[i];
            }
        }
        a[i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[j]==i) sum++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
