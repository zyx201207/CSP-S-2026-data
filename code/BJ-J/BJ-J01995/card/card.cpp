#include <iostream>
using namespace std;
int main(){
   freopen("card.in",r,stdin);
   freopen("card.out",w,stdout);
    int n,m;
    cin>>n>>m;
    int a[n],b[n]={0},sum[m]={0};
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
                b[j]=a[j];

            for(int k=i;k<j;k++){
                if(b[j]==a[k]){
                    int h=k;
                    do{
                        b[h]=0;
                        h++;
                    }while(b[h]!=a[k]);
                    k+=h;
                }
            }

        }
        for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(b[k]==j+1){
                        sum[j]++;
                        break;
                    }

                }
        }
        for(int j=0;j<n;j++)b[j]=0;
    }

    for(int i=0;i<m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
