#include<bits/stdc++.h>
using namespace std;
int c1(int n){
    int x=1,i=0;
    while(n>0){
        i+=n%2;
        n/=2;
    }
    return i;
}
bool cmp(int a,int b){
    if(c1(a)!=c1(b))return c1(a)>c1(b);
    else return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],c0=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)c0++;
    }
    if(c0%2==0)m-=c0;
    else m-=c0-1;
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    for(int i=1;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
	return 0;
}
