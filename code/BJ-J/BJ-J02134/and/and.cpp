#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],mmax=-1;
bool b[100000];
int mx(int a){
    int ans=1;
    while(ans*2<a) ans*=2;
    return ans;
}
int f(int a,int b){
    if(a&&b) return 1;
    else return 0;
    while(mx(a)!=mx(b)){
        if(mx(a)>mx(b)) a-=mx(a);
        if(mx(b)>mx(a)) b-=mx(b);
    }
    return mx(a)+f(a-mx(a),b-mx(b));
}
void em(int l,int r){
    int(int i=l;i<=r;i++) b[i]=0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans,lans,num;
    for(int i=1;i<=n-m+1;i++){
        b[i]=1;
        ans=a[i];
        for(int j=i+1;j<=n;j++){
            if(b[j]==0){
                lans=ans;
                num++;
                b[j]=1;
                ans=f(ans,a[j]);
            }
            if(num==m-1){
                if(ans>mmax) mmax=ans;
                ans=lans;
                num--;
            }
            if(j==n){
                em(i+2,n);
                j=i+1;
                ans=a[i];
            }
        }
        em(i+1,n);
    }
    cout<<mmax<<endl;
    return 0;
}