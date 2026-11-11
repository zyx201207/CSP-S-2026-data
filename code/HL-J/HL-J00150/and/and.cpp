#include<bits/stdc++.h>
using namespace std;
int const MAXN=1e6+5;
int num[MAXN];
int aa[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int a;
    int maxn=-1;
    for(int i=1;i<=m;i++){
        cin>>a;
        aa[a]+=1;
        if(a>maxn){
            maxn=a;
        }
        num[i]=a;

    }
    int max_cnt=0;
    if(n==2){
        for(int i=1;i<=maxn;i++){
            if(aa[i]>=2){
                max_cnt=i;
            }
        }
    }
    cout<<max_cnt;
    return 0;
}

