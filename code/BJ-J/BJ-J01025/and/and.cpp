#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return a>b;
}
long long a[200005],b[32][200005]={0},c[32],n,m,i,e,j,ans=0x7ffffffffffffff,d[200005],di=0,cnt;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cout<<sizeof(b)/1048576.0<<"MB"<<endl;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(i=0;i<n;i++){
        e=a[i];
        j=31;
        while(e){
            b[j][i]=e%2;
            c[j--]+=e%2;
            e/=2;
        }
    }
    //for(i=0;i<n;i++){
    //    for(j=0;j<32;j++)cout<<b[j][i]<<" ";
    //    cout<<endl;
    //}
    //for(i=0;i<32;i++)cout<<c[i]<<" ";
    for(i=0;c[i]<m;i++)if(c[i]>=m)break;
    //cout<<endl;
    //cout<<i;
    if(c[i]==m){
        for(j=0;j<n;j++){
            if(b[i][j]==1){
                ans&=a[j];
            }
        }
        //cout<<"ans1"<<endl;
        cout<<ans;
        return 0;
    }
    for(j=0;j<n;j++){
        if(b[i][j]==1){
            d[di++]=j;
        }
    }
    /*for(i=0;i<di;i++){
        for(j=0;j<32;j++)cout<<b[j][d[i]]<<" ";
        cout<<endl;
    }*/
    for(;i>0;i--){
        cnt=0;
        for(j=0;j<di;j++)if(d[j]!=-1)cnt+=b[i][d[j]];
        if(cnt<m)continue;
        for(j=0;j<di;j++){
            if(d[j]!=-1){
                if(b[i][d[j]]==0)d[j]=-1;
            }
        }
    }
    j=0;
    for(i=0;i<di&&j<m;i++)if(d[i]!=-1){ans&=a[d[i]];j++;}
    cout<<ans;
    return 0;
}
