#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000],h=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==2){
        int maxa=0,maxb=0;
        for(int i=1;i<=n;i++){
            if(a[i]>maxa){
                maxa]=a[i];
            }
            else if(a[i]==maxa){
            maxb=a[i];
            }
        }
        cout<<maxb;
    }
    if(m==3){
        int maxa=0,maxb=0,maxc=0;
        for(int i=1;i<=n;i++){
            if(a[i]>maxa){
                maxa=a[i];
            }
            else if(a[i]==maxa){
                maxb=a[i];
            }
            else if(a[i]==maxb){
                maxc=a[i];
            }
        }
        cout<<maxc;
    }
    if(m==4){
        int maxa=0,maxb=0,maxc=0,maxd=0;
        for(int i=1;i<=n;i++){
            if(a[i]>maxa){
                maxa=a[i];
            }
            else if(a[i]==maxa){
                maxb=a[i];
            }
            else if(a[i]==maxb){
                maxc=a[i];
            }
            else if(a[i]==maxc){
                maxd=a[i];
            }
        }
        cout<<maxd;
    }
    if(m==5){
        int maxa=0,maxb=0,maxc=0,maxd=0,maxe=0;
        for(int i=1;i<=n;i++){
            if(a[i]>maxa){
                maxa=a[i];
            }
            else if(a[i]==maxa){
                maxb=a[i];
            }
            else if(a[i]==maxb){
                maxc=a[i];
            }
            else if(a[i]==maxc){
                maxd=a[i];
            }
            else if(a[i]==maxd){
                maxe=a[i];
            }
        }
        cout<<maxe;
    }
    return 0;
}