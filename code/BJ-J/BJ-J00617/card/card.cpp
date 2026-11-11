#include<algorithm>
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;
int main(){
    freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
    int n,m,a[500005],ans[500005],b[300005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1,kk=0;i<=n;i++){
        for(int j=i,k=1;j<=n;j++,k++){
                b[k]=a[j];
            for(int l=1,s=b[k];l<=j-i+1;l++){
                if(b[l]==b[k]){
                    for(int h=l;h<=k;h++){
                        b[h]=0;
                    }
                    b[l]=s;
                    k=l;
                }
            }
            kk=k;
        }
        for(int j=1;j<=m;j++){
            for(int l=1;l<=kk;l++){
                if(j=b[l]){
                    ans[j]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
