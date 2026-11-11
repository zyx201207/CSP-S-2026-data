#include<bits/stdc++.h>
using namespace std;
long long n,m,max1=0,min1=10000000000,min2=0000000000,vmin,p,p1;
long long a[20005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>max1){
                max1=a[i];
        }
        if(a[i]<min1) {
                min1=a[i];
                vmin=i;
        }
        if(a[i]<min2&&vmin!=i){
            min2=a[i];
        }
    }if(m==1){
        cout<<max1;
        return 0;
    }if(m==n){
        cout<<min1;
        return 0;
    }if(m==n-1){
        cout<<min2;
        return 0;
    }
    if(m==2){
        max1=0;
        int q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                q=((a[i])&(a[j]));
                if(q>max1) max1=q;
            }
        }cout<<max1;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=m;i++){
        p=(p&a[i]);
        if(i>=2) p1=(p1&a[i]);
    }
    if(p>=p1) cout<<p;
    else cout<<p1;
    fclose(stdin);
    fclose(stdout);
}
