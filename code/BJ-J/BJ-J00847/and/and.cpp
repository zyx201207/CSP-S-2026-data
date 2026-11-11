#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxa=0,mina=200010,cmp,flag=0,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>maxa){
                    maxa=(a[i]&a[j]);
                }
            }
        }
    }else if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>maxa){
                maxa=a[i];
            }
        }
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
            if(a[i]<mina){
                mina=a[i];
                cmp=i;
            }
        }
        if(cmp!=1){
            ans=a[1];
        }
        else{
            ans=a[2];
            flag=1;
        }
        for(int i=1;i<=n;i++){
            if(i=cmp){
                continue;
            }
            if(flag==1&&i==2){
                continue;
            }else if(flag==0&&i==1){
                continue;
            }
            ans&=a[i];
        }
        cout<<ans<<endl;
        return 0;
    }else if(m==3){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if((a[i]&a[j]&a[k])>maxa){
                        maxa=(a[i]&a[j]&a[k]);
                    }
                }
            }
        }
    }else if(m==4){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int p=k+1;p<=n;p++){
                        if((a[i]&a[j]&a[k]&a[p])>maxa){
                            maxa=(a[i]&a[j]&a[k]&a[p]);
                        }
                    }
                }
            }
        }
    }else if(m==5){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int p=k+1;p<=n;p++){
                        for(int l=p+1;l<=n;l++){
                            if((a[i]&a[j]&a[k]&a[p]&a[l])>maxa){
                                maxa=(a[i]&a[j]&a[k]&a[p]&a[l]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<maxa<<endl;
    return 0;
}
