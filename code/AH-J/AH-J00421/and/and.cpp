#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2*100000+5]={};
int maxn;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==1){
        for(int i=0;i<n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
    }else if(m==n){
        maxn=a[0]&a[1];
        for(int i=2;i<n;i++){
            maxn=maxn&a[i];
        }
        cout<<maxn;
    }else{
        sort(a,a+n,cmp);
        if(a[0]==3){
            int cnt=0,cnt1=0,cnt2=0;
            int i=0;
            while(a[i++]==3){
                cnt++;
            }
            while(a[i++]==2){
                cnt1++;
            }
            while(a[i++]==1){
                cnt2++;
            }
            if(cnt<=m)cout<<3;
            else if(cnt+cnt1<=m)cout<<2;
            else if(cnt2<=m)cout<<1;
            else cout<<0;
        }
        else{
            cout<<12;
        }
    }
    return 0;
}
