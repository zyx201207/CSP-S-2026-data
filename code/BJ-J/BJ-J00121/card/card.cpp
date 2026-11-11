#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[200005],ans[200005],x[200005];
void clean(int a,int b){
    for(int i=a;i<=b;i++){
        x[i]=0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(x,0,sizeof(x));
        for(int j=i;j<=n;j++){
            int s=0;
            for(int k=i;k<=j;k++){
                if(x[i]==x[k]){
                    clean(i,k);
                    s=i-1;
                    break;
                }
            }
            x[++s]=a[j];
        }
        for(int j=1;j<=s;j++){
            ans[x[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[i];
    }
    return 0;
}
