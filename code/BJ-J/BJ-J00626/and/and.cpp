#include<bits/stdc++.h>
using namespace std;
int n,m,type[200005];
unsigned long long a[200005],ans,maxn;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    if(m==1) cout<<maxn;
    if(m==2){
        maxn=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) maxn=max((a[i]&a[j]),maxn);
        }
        cout<<maxn;
    }if(m==3){
        maxn=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               for(int k=j+1;k<n;k++) maxn=max(((a[i]&a[j])&a[k]),maxn);
            }
        }
        cout<<maxn;
    }if(m==4){
        maxn=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++) maxn=max(((a[i]&a[j])&(a[k]&a[l])),maxn);
                }
            }
        }
        cout<<maxn;
    }if(m==5){
        maxn=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        for(int p=l+1;p<n;p++) maxn=max(((a[i]&a[j])&(a[k]&a[l])&a[p]),maxn);
                    }
                }
            }
        }
        cout<<maxn;
    }if(m==6){
        maxn=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        for(int p=l+1;p<n;p++){
                            for(int q=p+1;q<n;q++) maxn=max(((a[i]&a[j])&(a[k]&a[l])&(a[p]&a[q])),maxn);
                        }
                    }
                }
            }
        }
        cout<<maxn;
    }if(m==7){
        maxn=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        for(int p=l+1;p<n;p++){
                            for(int q=p+1;q<n;q++){
                                for(int r=r+1;r<n;r++) maxn=max(((a[i]&a[j])&(a[k]&a[l])&(a[p]&a[q])&a[r]),maxn);
                            }
                        }
                    }
                }
            }
        }
        cout<<maxn;
    }if(m==n&&m>7){
        for(int i=0;i<n;i++){
            if(i==0) maxn=a[0];
            else maxn=(a[0]&maxn);
        }
        cout<<maxn;
    }
    return 0;
}