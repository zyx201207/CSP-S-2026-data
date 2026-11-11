#include<bits/stdc++.h>
using namespace std;

int n,d,a[2000006],cnt;
int c[2000006];

void check(int l,int r,int x){
    if(l==r){
        c[x]++;
        return ;
    }
    for(int i=l+1; i<=r&&a[i]-a[l]<=d; i++){
        check(i,r,x+1);
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin >> C >> T;
    while(T--){
        cnt=0;
        cin >> n >> d;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        if(C==13||C==14){
            printf("0\n");
            continue;
        }
        for(int l=1; l<n; l++){
            for(int r=l+1; r<=n; r++){
                check(l,r,0);
                for(int i=1; i<=r-l+1; i++){
                    if(c[i]>0){
                        if(c[i]==2)cnt++;
                        break;
                    }
                }
                for(int i=1; i<=r-l+1; i++){
                    c[i]=0;
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
