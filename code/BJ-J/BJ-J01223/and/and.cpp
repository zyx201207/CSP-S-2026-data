#include<iostream>
#include<algorithm>
using namespace std;

int a[2000001];

bool cmp(int a,int b){return a>b;}

bool pow2(int i){
    if(i-(i&-i)==0)return 1;
    return 0;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,tot=0,ans=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(pow2(a[i]))tot++;
    }
    sort(a+1,a+n+1,cmp);
    int cnt=1;
    for(int i=1;i<=n&&cnt<=m;i++){
        if(pow2(a[i])&&n-i>m-cnt)continue;
        ans&=a[i],cnt++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
