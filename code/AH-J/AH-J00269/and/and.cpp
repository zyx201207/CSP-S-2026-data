#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200005],ans=2147483647;
map<int,int> bin1;
int num1bin(int x){
    int cnt=0;
    while(x){
        cnt+=(x&1);
        x>>=1;
    }return cnt;
}bool cmp(int a,int b){
    if(bin1[a]!=bin1[b]) return bin1[a]>bin1[b];
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        bin1[a[i]]=num1bin(a[i]);
    }sort(a+1,a+1+n,cmp);
    //for(int i=1;i<=n;i++){
  //      cout<<a[i]<<"\n";
//    }
    for(int i=1;i<=m;i++){
        ans&=a[i];
    }cout<<ans;
    return 0;
}//先拿一半分再说
