#include<bits/stdc++.h>
using namespace std;
int a[100005];
int t[150];
int kx[1000005];
long long aaa[35];
void alibaba(){
    a[1]=2;
    for(int i=2;i<=30;i++){
        a[i]=a[i-1]*2;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    alibaba();
    int n,m,s;
    cin>>n>>m;
    if(m==n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1){
                s=a[1];
            }else{
                s=s&a[i];
            }
        }
        cout<<s;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }else{
        sort(a+1,a+1+n);
        int cnt=0;
        for(int i=n;i>=1;i--){
            bool d=1;
            for(int j=1;j<=30;j++){
                if(a[i]==aaa[j]){
                    d=0;
                    break;
                }
            }
            if(d){
                cnt++;
                kx[cnt]=a[i];
                if(cnt==m){
                    break;
                }
            }
        }
        if(cnt<m){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=30;j++){
                    if(a[i]==aaa[j]){
                        cnt++;
                        kx[cnt]=a[i];
                        break;
                    }
                }
                if(cnt==m){
                    break;
                }
            }
        }
        int ss=0;
        for(int i=1;i<=m;i++){
            if(i==1){
                ss=kx[1];
            }else{
                ss=ss&kx[i];
            }
        }
        cout<<ss;
    }
    return 0;
}
