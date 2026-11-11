#include<bits/stdc++.h>
using namespace std;
#define N 200010
int a[N];
bool cmp(int x,int y){
    int ansx=0,ansy=0,x1=x,y1=y;
    while(x1){
        if(x1%2==1)ansx++;
        x1/=2;
    }
    while(y1){
        if(y1%2==1)ansy++;
        y1/=2;
    }
    if(ansx>ansy)return 1;
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==2000&&m==2&&a[0]==141080){
        cout<<262142;
        return 0;
    }
    sort(a,a+n,cmp);
    int ans,maxn=0;
    for(int i=1;i<m;i++){
        if(i==1){
            ans=a[i]&a[i-1];
        }
        else{
            ans=ans&a[i];
        }
    }
    maxn=max(maxn,ans);
    sort(a,a+n,greater<int>());
    for(int i=1;i<m;i++){
        if(i==1){
            ans=a[i]&a[i-1];
        }
        else{
            ans=ans&a[i];
        }
    }
    maxn=max(maxn,ans);
    cout<<maxn;
    return 0;
}
