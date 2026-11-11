#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200008];
int maxx=0;
int btt[5];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        if(a[i]>=4) f=0;
        else if(a[i]==1) btt[1]++;
        else if(a[i]==2) btt[2]++;
        else if(a[i]==3) btt[3]++;
    }
    if(m==1) cout<<maxx;
    else if(m==2){
        maxx=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int k=(a[i]&a[j]);
                maxx=max(maxx,k);
            }
        }
        cout<<maxx;
    }
    else if(m==n){
        maxx=0;
        int k=a[1];
        for(int i=2;i<=n;i++){
            k=k&a[i];
            maxx=max(maxx,k);
        }
        cout<<maxx;
    }
    else if(f){
        maxx=0;
        if(btt[3]>=m) maxx=3;
        else if(btt[2]+btt[3]>=m) maxx=2;
        else if(btt[1]+btt[3]>=m) maxx=1;
        cout<<maxx;
    }
    else{
        sort(a+1,a+1+n,cmp);
        int k=a[1];
        for(int i=2;i<=m;i++){
            k=k&a[i];
        }
        cout<<k;
    }
    return 0;
}
