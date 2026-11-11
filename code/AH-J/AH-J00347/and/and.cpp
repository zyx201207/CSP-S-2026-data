#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],mx,sum[N],num[N],pos;
bool f=1,l=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1) f=0;
        if(a[i]>=4) l=0;
    }
    sum[1]=a[2];
    for(int i=2;i<=n;i++) sum[i]=a[1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) sum[j]&=a[i];
        }
    }
    sort(a+1,a+n+1);
    if(f||l){
        mx=a[n];
        for(int i=n-1;i>=n-m+1;i--) mx&=a[i];
        cout<<mx;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++) mx=max(mx,a[i]&a[j]);
        }
        cout<<mx;
        return 0;
    }else if(m==n){
        mx=a[1];
        for(int i=2;i<=n;i++) mx&=a[i];
        cout<<mx;
        return 0;
    }else if(m==1){
        cout<<a[n];
        return 0;
    }else if(m==n-1){
        for(int i=1;i<=n;i++) mx=max(mx,sum[i]);
        cout<<mx;
        return 0;
    }else{
        cout<<a[n-m+1];
        return 0;
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++) mx=max(mx,a[i]&a[j]&a[k]);
            }
        }
    }else if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++) mx=max(mx,a[i]&a[j]&a[k]&a[l]);
                }
            }
        }
    }else if(m==5){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++) mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]);
                    }
                }
            }
        }
    }else if(m==6){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++){
                            for(int h=1;h<r;h++) mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]&a[h]);
                        }
                    }
                }
            }
        }
    }else if(m==7){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++){
                            for(int h=1;h<r;h++){
                                for(int e=1;e<h;e++) mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]&a[h]&a[e]);
                            }
                        }
                    }
                }
            }
        }
    }else if(m==8){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++){
                            for(int h=1;h<r;h++){
                                for(int e=1;e<h;e++){
                                    for(int g=1;g<e;g++){
                                        mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]&a[h]&a[e]&a[g]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(m==9){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++){
                            for(int h=1;h<r;h++){
                                for(int e=1;e<h;e++){
                                    for(int g=1;g<e;g++){
                                        for(int p=1;p<g;p++){
                                            mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]&a[h]&a[e]&a[g]&a[p]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(m==10){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++){
                            for(int h=1;h<r;h++){
                                for(int e=1;e<h;e++){
                                    for(int g=1;g<e;g++){
                                        for(int p=1;p<g;p++){
                                            for(int q=1;q<p;q++){
                                                mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]&a[h]&a[e]&a[g]&a[p]&a[q]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(m==11){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++){
                            for(int h=1;h<r;h++){
                                for(int e=1;e<h;e++){
                                    for(int g=1;g<e;g++){
                                        for(int p=1;p<g;p++){
                                            for(int q=1;q<p;q++){
                                                for(int u=1;u<q;u++){
                                                    mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]&a[h]&a[e]&a[g]&a[p]&a[q]&a[u]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(m==12){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++){
                            for(int h=1;h<r;h++){
                                for(int e=1;e<h;e++){
                                    for(int g=1;g<e;g++){
                                        for(int p=1;p<g;p++){
                                            for(int q=1;q<p;q++){
                                                for(int u=1;u<q;u++){
                                                    for(int v=1;v<u;v++){
                                                        mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]&a[h]&a[e]&a[g]&a[p]&a[q]&a[u]&a[v]);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(m==13){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int r=1;r<l;r++){
                            for(int h=1;h<r;h++){
                                for(int e=1;e<h;e++){
                                    for(int g=1;g<e;g++){
                                        for(int p=1;p<g;p++){
                                            for(int q=1;q<p;q++){
                                                for(int u=1;u<q;u++){
                                                    for(int v=1;v<u;v++){
                                                        for(int w=1;w<v;w++){
                                                            mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[r]&a[h]&a[e]&a[g]&a[p]&a[q]&a[u]&a[v]&a[w]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
