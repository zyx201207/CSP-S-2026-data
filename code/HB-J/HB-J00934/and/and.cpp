#include<bits/stdc++.h>
using namespace std;
long long a[200001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int zzh=0;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        int h=a[i];
        int gs=1;
        for(int j=i+1;j<n;j++){
            if(gs==m) break;
            if((h&a[j])==0) continue;
            else{
                h=h&a[j];
                gs++;
            }
        }
        if(gs==m && h!=0){
            zzh=h;
            break;
        }
    }
    cout<<zzh;
    return 0;
}
