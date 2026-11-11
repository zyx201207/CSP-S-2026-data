#include<bits/stdc++.h>
using namespace std;

int a[200005][100];
long long cnt[100];
bool fail[200005];
int ans[100];

int slv(int x,int i){
    int k=0;
    while(x){
        k++;
        a[i][k]=x%2;
        x/=2;
    }
    return k;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    int mk=-1;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        mk=max(mk,slv(x,i));
    }
    for(int i=mk;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(a[j][i]==1) cnt[i]++;
        }
    }
    int fs=-1,rm=n;
    for(int i=mk;i>=1;i--){
        if(cnt[i]>=m && fs==-1) fs=i;
        if(fs==-1) continue;
        if(cnt[i]<m) continue;
        //taotai
        int j=1;
        while(j<=n && rm>m){
            if(a[j][i]==0){
                rm--;
                fail[j]=1;
                for(int l=1;l<=mk;l++){
                    if(a[j][l]==1) cnt[l]--;
                }
            }
            j++;
        }//
        if(rm==m) break;
    }
    int ck=0;
    for(int i=1;i<=n;i++){
        if(fail[i]==1) continue;
        ck++;
        for(int j=1;j<=mk;j++){
            if(ck==1) ans[j]=a[i][j];
            else{
                ans[j]=ans[j] & a[i][j];
            }
        }
    }
    long long las=0,q=1;
    for(int i=1;i<=mk;i++){
        las+=ans[i]*q;
        q*=2;
    }
    cout << las;
    return 0;
}
