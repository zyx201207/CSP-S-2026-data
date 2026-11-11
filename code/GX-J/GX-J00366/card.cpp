#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[100003],b[100003],d[100003];
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=0;
        d[i]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if(j==1) b[j]=a[i];
            for (int k=i;k<=j;k++){
                if (a[j] != b[k]){
                    b[j] = a[j];
                }else{
                    for (int l=k;l<=j;l++){
                        b[l] = 0;
                    }
                    b[k] = a[j];
                    break;
                }
            }
        }
        for (int j=i;j<=m;j++){
            for (int k=i;k<=n;k++){
                if (b[k]==j){
                    d[j]+=1;
                }
            }
        }
    }
    for (int i=1;i<=m;i++){
        cout << d[m] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
