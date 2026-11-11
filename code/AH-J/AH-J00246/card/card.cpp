#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long b[300005],c[300005],a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,pos;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        pos=i;
        for(int j=i;j<=n;j++){
            b[a[j]]++;
            if(b[a[j]]>1){
                for(int k=pos+1;k<j;k++){
                    if(a[k]==a[j]){
                        pos=k;
                        break;
                    }
                }
                for(int k=pos;k<j;k++){
                    if(b[a[k]]>0){
                        b[a[k]]--;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(b[i]!=0){
                c[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
