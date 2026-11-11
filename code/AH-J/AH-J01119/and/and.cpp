#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],mx=INT_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)cin>>a[i];
    if(n==2){
        for(int i=1;i<=m-1;i++){
            for(int j=i+1;j<=m;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
    }else if(n==3){
        for(int i=1;i<=m-2;i++){
            for(int j=i+1;j<=m-1;j++){
                for(int k=j+1;k<=m;k++){
                    mx=max(mx,a[i]&a[j]&a[k]);
                }
            }
        }
    }else if(n==4){
        for(int i=1;i<=m-3;i++){
            for(int j=i+1;j<=m-2;j++){
                for(int k=j+1;k<=m-1;k++){
                    for(int l=k+1;l<=m;l++){
                            mx=max(mx,a[i]&a[j]&a[k]&a[l]);
                    }
                }
            }
        }
    }else if(n==5){
        for(int i=1;i<=m-4;i++){
            for(int j=i+1;j<=m-3;j++){
                for(int k=j+1;k<=m-2;k++){
                    for(int l=k+1;l<=m-1;l++){
                        for(int o=l+1;o<=m;o++){
                            mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]);
                        }
                    }
                }
            }
        }
    }else if(n==6){
        for(int i=1;i<=m-5;i++){
            for(int j=i+1;j<=m-4;j++){
                for(int k=j+1;k<=m-3;k++){
                    for(int l=k+1;l<=m-2;l++){
                        for(int o=l+1;o<=m-1;o++){
                            for(int p=o+1;p<=m;p++){
                                mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
                            }
                        }
                    }
                }
            }
        }
    }else if(n==7){
        for(int i=1;i<=m-6;i++){
            for(int j=i+1;j<=m-5;j++){
                for(int k=j+1;k<=m-4;k++){
                    for(int l=k+1;l<=m-3;l++){
                        for(int o=l+1;o<=m-2;o++){
                            for(int p=o+1;p<=m-1;p++){
                                for(int q=p+1;q<=m;q++){
                                    mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(n==8){
        for(int i=1;i<=m-7;i++){
            for(int j=i+1;j<=m-6;j++){
                for(int k=j+1;k<=m-5;k++){
                    for(int l=k+1;l<=m-4;l++){
                        for(int o=l+1;o<=m-3;o++){
                            for(int p=o+1;p<=m-2;p++){
                                for(int q=p+1;q<=m-1;q++){
                                    for(int r=q+1;r<=m;r++){
                                        mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(n==9){
        for(int i=1;i<=m-8;i++){
            for(int j=i+1;j<=m-7;j++){
                for(int k=j+1;k<=m-6;k++){
                    for(int l=k+1;l<=m-5;l++){
                        for(int o=l+1;o<=m-4;o++){
                            for(int p=o+1;p<=m-3;p++){
                                for(int q=p+1;q<=m-2;q++){
                                    for(int r=q+1;r<=m-1;r++){
                                        for(int s=r+1;s<=m;s++){
                                            mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(n==10){
        for(int i=1;i<=m-9;i++){
            for(int j=i+1;j<=m-8;j++){
                for(int k=j+1;k<=m-7;k++){
                    for(int l=k+1;l<=m-6;l++){
                        for(int o=l+1;o<=m-5;o++){
                            for(int p=o+1;p<=m-4;p++){
                                for(int q=p+1;q<=m-3;q++){
                                    for(int r=q+1;r<=m-2;r++){
                                        for(int s=r+1;s<=m-1;s++){
                                            for(int t=s+1;t<=m;t++){
                                                mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]);
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
    }else if(n==11){
        for(int i=1;i<=m-10;i++){
            for(int j=i+1;j<=m-9;j++){
                for(int k=j+1;k<=m-8;k++){
                    for(int l=k+1;l<=m-7;l++){
                        for(int o=l+1;o<=m-6;o++){
                            for(int p=o+1;p<=m-5;p++){
                                for(int q=p+1;q<=m-4;q++){
                                    for(int r=q+1;r<=m-3;r++){
                                        for(int s=r+1;s<=m-2;s++){
                                            for(int t=s+1;t<=m-1;t++){
                                                for(int u=t+1;u<=m;u++){
                                                    mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]);
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
    }else if(n==12){
        for(int i=1;i<=m-11;i++){
            for(int j=i+1;j<=m-10;j++){
                for(int k=j+1;k<=m-9;k++){
                    for(int l=k+1;l<=m-8;l++){
                        for(int o=l+1;o<=m-7;o++){
                            for(int p=o+1;p<=m-6;p++){
                                for(int q=p+1;q<=m-5;q++){
                                    for(int r=q+1;r<=m-4;r++){
                                        for(int s=r+1;s<=m-3;s++){
                                            for(int t=s+1;t<=m-2;t++){
                                                for(int u=t+1;u<=m-1;u++){
                                                    for(int v=u+1;v<=m;v++){
                                                        mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]);
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
    }else if(n==13){
        for(int i=1;i<=m-12;i++){
            for(int j=i+1;j<=m-11;j++){
                for(int k=j+1;k<=m-10;k++){
                    for(int l=k+1;l<=m-9;l++){
                        for(int o=l+1;o<=m-8;o++){
                            for(int p=o+1;p<=m-7;p++){
                                for(int q=p+1;q<=m-6;q++){
                                    for(int r=q+1;r<=m-5;r++){
                                        for(int s=r+1;s<=m-4;s++){
                                            for(int t=s+1;t<=m-3;t++){
                                                for(int u=t+1;u<=m-2;u++){
                                                    for(int v=u+1;v<=m-1;v++){
                                                        for(int w=v+1;w<=m;w++){
                                                            mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]);
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
    }else if(n==14){
        for(int i=1;i<=m-13;i++){
            for(int j=i+1;j<=m-12;j++){
                for(int k=j+1;k<=m-11;k++){
                    for(int l=k+1;l<=m-10;l++){
                        for(int o=l+1;o<=m-9;o++){
                            for(int p=o+1;p<=m-8;p++){
                                for(int q=p+1;q<=m-7;q++){
                                    for(int r=q+1;r<=m-6;r++){
                                        for(int s=r+1;s<=m-5;s++){
                                            for(int t=s+1;t<=m-4;t++){
                                                for(int u=t+1;u<=m-3;u++){
                                                    for(int v=u+1;v<=m-2;v++){
                                                        for(int w=v+1;w<=m-1;w++){
                                                            for(int x=w+1;x<=m;x++){
                                                                mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]);
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
    }else if(n==15){
        for(int i=1;i<=m-14;i++){
            for(int j=i+1;j<=m-13;j++){
                for(int k=j+1;k<=m-12;k++){
                    for(int l=k+1;l<=m-11;l++){
                        for(int o=l+1;o<=m-10;o++){
                            for(int p=o+1;p<=m-9;p++){
                                for(int q=p+1;q<=m-8;q++){
                                    for(int r=q+1;r<=m-7;r++){
                                        for(int s=r+1;s<=m-6;s++){
                                            for(int t=s+1;t<=m-5;t++){
                                                for(int u=t+1;u<=m-4;u++){
                                                    for(int v=u+1;v<=m-3;v++){
                                                        for(int w=v+1;w<=m-2;w++){
                                                            for(int x=w+1;x<=m-1;x++){
                                                                for(int y=x+1;y<=m;y++){
                                                                    mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y]);
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
        }
    }else if(n==16){
        for(int i=1;i<=m-15;i++){
            for(int j=i+1;j<=m-14;j++){
                for(int k=j+1;k<=m-13;k++){
                    for(int l=k+1;l<=m-12;l++){
                        for(int o=l+1;o<=m-11;o++){
                            for(int p=o+1;p<=m-10;p++){
                                for(int q=p+1;q<=m-9;q++){
                                    for(int r=q+1;r<=m-8;r++){
                                        for(int s=r+1;s<=m-7;s++){
                                            for(int t=s+1;t<=m-6;t++){
                                                for(int u=t+1;u<=m-5;u++){
                                                    for(int v=u+1;v<=m-4;v++){
                                                        for(int w=v+1;w<=m-3;w++){
                                                            for(int x=w+1;x<=m-2;x++){
                                                                for(int y=x+1;y<=m-1;y++){
                                                                    for(int z=y+1;z<=m;z++){
                                                                        mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]);
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
            }
        }
    }
    cout<<mx;
    return 0;
}
