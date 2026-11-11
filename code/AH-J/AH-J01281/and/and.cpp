#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,x[N][40],w[N],r[N];
struct node{
    int ai,t;
}a[N];
void init(int i){
    int s=30,b=a[i].ai;
    while(b!=0){
        if(b>=w[s]){
            b-=w[s];
            a[i].t++;
            x[i][s]=1;
            x[0][s]++;
        }
        s--;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    w[0]=1;
    for(int i=1;i<=30;i++){
        w[i]=w[i-1]*2;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].ai);
        init(i);
    }
    int v;
    for(int i=30;i>=0;i--){
        if(x[0][i]>=m){
            v=i;
            break;
        }
    }
    int c=0,ans=INT_MAX;
    for(int i=1;i<=n;i++)if(x[i][v]==1)r[++c]=i;
    if(x[0][v]==m){
        for(int i=1;i<=c;i++)ans=ans&a[r[c]].ai;
        cout<<ans;
        return 0;
    }
    for(int i=v-1;i>=0;i--){
        x[0][i]=0;
        for(int j=1;j<=c;j++)x[0][i]+=x[r[j]][i];
        if(x[0][i]>=m)for(int j=1;j<=c;j++)if(x[r[j]][i]!=1)r[j]=1e9;
        sort(r+1,r+1+c);
        c=x[0][i];
    }
    for(int i=1;i<=m;i++)ans=ans&a[r[c]].ai;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
