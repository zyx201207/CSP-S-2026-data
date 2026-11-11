#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005];
int aa[200005],cnt[200005];
int b[35],ans[35];
vector<int> c[35];

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int nn=1;
    aa[1]=a[1];
    cnt[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            cnt[nn]++;
        }else{
            aa[++nn]=a[i];
            cnt[nn]=1;
        }
    }
    n=nn;

    for(int i=1;i<=n;i++){
        int x=aa[i];
        int l=0;
        while(x!=0){
            if(x&1){
                b[l]=1;
            }else{
                b[l]=0;
            }
            l++;
            x/=2;
        }
        int r=0;
        for(int j=0;j<l;j++){
            if(b[j]==1){
                c[r].push_back(i);
                ans[r]+=cnt[i];
            }
            r++;
        }
        for(int j=0;j<l;j++){
            b[j]=0;
        }
    }

    long long num=0;
    for(int k=31;k>=0;k--){
        if(ans[k]>=m){
            num+=(1ll<<(k));
            vector<int> cc;
            cc=c[k];

            for(int i=0;i<=31;i++) {
                ans[i]=0;
                c[i].clear();
            }
            for(auto y:cc){
                int x=aa[y];
                int l=0;
                while(x!=0){
                    if(x&1){
                        b[l]=1;
                    }else{
                        b[l]=0;
                    }
                    l++;
                    x/=2;
                }
                int r=0;
                for(int j=0;j<l;j++){
                    if(b[j]==1){
                        c[r].push_back(y);
                        ans[r]+=cnt[y];
                    }
                    r++;
                }
                for(int i=0;i<l;i++){
                    b[i]=0;
                }
            }
        }
    }
    cout<<num<<"\n";
    return 0;
}
