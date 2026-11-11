#include <iostream>
using namespace std;
int a[500005],n,m,b[300005],c[500005],d[300005];
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[j]=0;
            c[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(d[a[j]])for(int k=d[a[j]];k<=j;k++){
                if(d[c[k]]==k)d[c[k]]=0;
                c[k]=0;
            }
            c[j]=a[j];
            d[c[j]]=j;
        }
        for(int j=1;j<=m;j++)if(d[j])b[j]++;
    }
    for(int i=1;i<=m;i++)cout << b[i] << " ";
    return 0;
}
