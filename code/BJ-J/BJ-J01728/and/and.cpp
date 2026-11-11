#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;

struct cla{
    short wei[35];
    int act;
};
int n,m;

int can=-1;
cla a[N];
void work(int i){
    int x=a[i].act,temp=0;
    while(x){
        if(x&1){
            a[i].wei[temp]=1;
        }else a[i].wei[temp]=0;
        temp++;
        x>>=1;
    }
    return ;
}
int check(int mid){
    bool f=0;
    int cnt=0,zhi=0;
    for(int i=1;i<=n;i++){
        if(a[i].wei[mid]==1){
            cnt++;
            if(f==0){
                zhi=a[i].act;
                f=1;
            }
            zhi=zhi&a[i].act;
        }
    }
    if(cnt>=m) return zhi;
    else return 0;
}
int use[N];
bool cmp(int x,int y){
    return x>y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].act;
        work(i);
    }
    int l=0,r=30,mid;
    while(l<=r){
        mid=(l+r)/2;
        int zhi=check(mid);
        if(zhi>0){
            l=mid+1;
            can=max(can,mid);
        }else{
            r=mid-1;
        }
    }
    if(can==-1){
        cout<<"0";
        return 0;
    }

    int temp=0;
    for(int i=1;i<=n;i++){
        if(a[i].wei[can]==1){
            use[++temp]=a[i].act;
        }
    }
    sort(use+1,use+temp+1,cmp);
    for(int i=2;i<=min(m+1,temp);i++){
        use[i]=use[i-1]&use[i];
    }
    cout<<use[m];
}
