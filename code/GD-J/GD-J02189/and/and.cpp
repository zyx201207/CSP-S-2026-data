#include<bits/stdc++.h>
using namespace std;
const int MAX=(1e5+5)*2;
int n,m,a[MAX],b[MAX];
int ans=0;
struct two_t{
    int two,pos;
}twooo[MAX];
bool cmp(two_t x,two_t y){
    return x.two>y.two;
}
int answers(int k){
    int sum=a[1];
    for(int i=2;i<=n;i++){
        if(i==k) continue;
        sum=sum&a[i];
    }
    return sum;
}
int not_perfect(){
    for(int i=1;i<=n;i++){
        twooo[i].pos=i;
        while(a[i]){
            if(a[i]%2==1) twooo[i].two++;
            a[i]/=2;
        }
    }
    sort(twooo+1,twooo+n+1,cmp);
    int num=b[twooo[1].pos];
    for(int i=2;i<=m;i++){
        num=b[twooo[i].pos]&num;
    }
    return num;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(a[i],ans);
        }
    }
    else if(m==n){
        for(int i=1;i<=n;i++){
            ans=a[i]&ans;
        }
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            ans=max(answers(i),ans);
        }
    }
    else if(m==2&&n<=2000){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(a[i]&a[j],ans);
            }
        }
    }
    else{
        ans=not_perfect();
    }
    cout<<ans;
    return 0;
}
