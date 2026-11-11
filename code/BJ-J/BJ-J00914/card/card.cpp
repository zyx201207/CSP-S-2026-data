#include <iostream>
#include <cstring>
using namesapce std;
freopen("card.in","r",std.in)
freopen("card.out","w",std.out)
int main()
{
    int a,b;
    int c[1500000];
    int d[510000];
    int e[510000];
    int f[510000];
    cin >> a >> b;
    for(int i=1;i<a;i++){
        cin >> c[i];
    }
    for(int i=1;i<=b;i++){
       e[i]=i;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
             for(int k=1;k<=b;k++;{
             if(c[j]==d[k]&&c[j]!=0){
             d[k]=c[j];
             for(int z=k+1;z<=b;z++) {
             d[z]=0;
             }
             }
             else if(d[k]==0){
             d[k]=c[j];
             c[j]=0;
             }
             if(j==a&&k==b){
                 for(int y=1;i<=b;y++){
                    for(int x=1;x<=b;x++){
                       if(d[x]==e[y]){
                           f[y]++;
                       }
                    }
                 }
                 e={0};
                 d={0};
             }
             }
             
        }
    }
    for(int i=1;i<=b;i++){
         cout << f[i] << " ";
    }
return 0;
}