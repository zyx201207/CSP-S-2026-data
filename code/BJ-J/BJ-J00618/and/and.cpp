#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int pre[40],n,m,a[N],tmp[N],s[N][40],t[N][40];
int maxl;
int f[N],ans;
int tmp1[N],t1[N][40];
void bulid(){
    pre[0]=1;
    for(int i=1;i<=30;i++){
        pre[i]=pre[i-1]*2;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bulid();
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    memcpy(tmp,a,sizeof(tmp));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=35;j++)t[i][j]=t[i-1][j];
        while(tmp[i]){
            int x=log2(tmp[i]&(-tmp[i]));
            s[i][x]++;
            t[i][x]++;
            tmp[i]-=(tmp[i]&(-tmp[i]));
            maxl=max(maxl,x);
        }
    }
    maxl++;
    int k=0,inx=0;//zui gao fu he wei
    for(int i=maxl-1;i>=0;i--){
        if(t[n][i]>=m){
            k=i;
            break;
        }
    }
  
        //fu he shu
    for(int i=1;i<=n;i++){
        if(s[i][k]){
            f[++inx]=a[i];
        }
    }
 
    //
    //qian zhui he t shu zu 
    memcpy(tmp1,f,sizeof(tmp1));
    for(int i=1;i<=inx;i++){
        for(int j=0;j<=35;j++)t1[i][j]=t1[i-1][j];
        while(tmp1[i]){
            int x=log2(tmp1[i]&(-tmp1[i]));
            t1[i][x]++;
            tmp1[i]-=(tmp1[i]&(-tmp1[i]));
        }
    }
    int l=1,r=inx,o=k;
    for(int i=o;i>=0;i--){
        while(r-l+1>t1[inx][i]&&t1[inx][i]>=m){
            l++;
            while(f[l]){
                int x=log2(f[l]&(-f[l]));
                t1[inx][x]--;
                f[l]-=(f[l]&(-f[l]));
            }
        }
        if(t1[inx][i]>=m){
            ans+=pre[i];
        }
    }
    cout<<ans;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}