#include<bits/stdc++.h>
using namespace std;
long long a[200005],cnt,ans;
bool cmp(long long x,long long y){return x>y;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,pos;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1,cmp);
    cnt=a[1];
    //for(int i=30;i>=1;i++){
        //if(pow(2,i)<=cnt)pos=i;
    //}
    for(int i=1;i<=m;i++){
        cnt=cnt&a[i];
    }
    /*for(int i=1;i<=m;){
        if(a[i]<=pow(2,pos)){
            ans=ans&a[i];
            i++;
        }
    }*/
    //ans=pow(2,pos-1)-1;
    cout<<cnt;
}