#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[500005],t[300005],tt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            t[a[j]]=1;
            if(a[j]==a[j-1]){
                t[a[j]]=0;
                i++;
            }
        }
        for(int j=1;j<=m;j++){
            tt[a[j]]+=t[a[j]];
        }
        memset(t,0,sizeof(t));
    }
    for(int i=1;i<=m;i++){
        cout<<tt[a[i]]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
