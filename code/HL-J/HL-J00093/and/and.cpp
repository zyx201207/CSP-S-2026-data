#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            if(maxx<a[i]){
                maxx=a[i];
            }
        }
        cout<<maxx;
    }else if(m==n){
        long long sum=a[0];
        for(int i=1;i<n;i++){
            sum=(sum & a[i]);
        }
        cout<<sum;
    }else if(m==2){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    long long sum=(a[i] & a[j]);
                    if(maxx<sum){
                        maxx=sum;
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==3){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    if(i!=j && i!=l && j!=l){
                        long long sum=(a[i] & a[j] & a[l]);
                        if(maxx<sum){
                            maxx=sum;
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==4){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    for(int t=0;t<n;t++){
                        if(i!=j && i!=l && i!=t && j!=l && j!=t && l!=t){
                            long long sum=(a[i] & a[j] & a[l] & a[t]);
                            if(maxx<sum){
                                maxx=sum;
                            }
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==5){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    for(int t=0;t<n;t++){
                        for(int y=0;y<n;y++){
                            if(i!=j && i!=l && i!=t && i!=y && j!=l && j!=t && l!=t && j!=y && l!=y && t!=y){
                                long long sum=(a[i] & a[j] & a[l] & a[t] & a[y]);
                                if(maxx<sum){
                                    maxx=sum;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==6){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    for(int t=0;t<n;t++){
                        for(int y=0;y<n;y++){
                            for(int z=0;z<n;z++){
                                if(i!=j && i!=l && i!=t && i!=y && i!=z && j!=l && j!=t && l!=t && j!=y && l!=y && t!=y && j!=z && l!=z && t!=z && y!=z){
                                    long long sum=(a[i] & a[j] & a[l] & a[t] & a[y] & a[z]);
                                    if(maxx<sum){
                                        maxx=sum;
                                    }
                                }

                            }
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==7){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    for(int t=0;t<n;t++){
                        for(int y=0;y<n;y++){
                            for(int z=0;z<n;z++){
                                for(int k=0;k<n;k++){
                                    if(i!=j && i!=l && i!=t && i!=y && i!=z && i!=k && j!=l && j!=t && l!=t && j!=y && l!=y && t!=y && j!=z && l!=z && t!=z && y!=z && j!=k && l!=k && t!=k && y!=k && z!=k){
                                        long long sum=(a[i] & a[j] & a[l] & a[t] & a[y] & a[z] & a[k]);
                                        if(maxx<sum){
                                            maxx=sum;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==8){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    for(int t=0;t<n;t++){
                        for(int y=0;y<n;y++){
                            for(int z=0;z<n;z++){
                                for(int k=0;k<n;k++){
                                    for(int u=0;u<n;u++){
                                        if(i!=j && i!=l && i!=t && i!=y && i!=z && i!=k && i!=u && j!=l && j!=t && l!=t && j!=y && l!=y && t!=y && j!=z && l!=z && t!=z && y!=z && j!=k && l!=k && t!=k && y!=k && z!=k && j!=u && l!=u && t!=u && y!=u && z!=u && k!=u){
                                            long long sum=(a[i] & a[j] & a[l] & a[t] & a[y] & a[z] & a[k] & a[u]);
                                            if(maxx<sum){
                                                maxx=sum;
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
        cout<<maxx;
    }else if(m==9){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    for(int t=0;t<n;t++){
                        for(int y=0;y<n;y++){
                            for(int z=0;z<n;z++){
                                for(int k=0;k<n;k++){
                                    for(int u=0;u<n;u++){
                                        for(int q=0;q<n;q++){
                                            if(i!=j && i!=l && i!=t && i!=y && i!=z && i!=k && i!=u && i!=q && j!=l && j!=t && l!=t && j!=y && l!=y && t!=y && j!=z && l!=z && t!=z && y!=z && j!=k && l!=k && t!=k && y!=k && z!=k && j!=u && l!=u && t!=u && y!=u && z!=u && k!=u && j!=q && l!=q && t!=q && y!=q && z!=q && k!=q && u!=q){
                                                long long sum=(a[i] & a[j] & a[l] & a[t] & a[y] & a[z] & a[k] & a[u] & a[q]);
                                                if(maxx<sum){
                                                    maxx=sum;
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
        cout<<maxx;
    }else if(m==10){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    for(int t=0;t<n;t++){
                        for(int y=0;y<n;y++){
                            for(int z=0;z<n;z++){
                                for(int k=0;k<n;k++){
                                    for(int u=0;u<n;u++){
                                        for(int q=0;q<n;q++){
                                            for(int w=0;w<n;w++){
                                                if(i!=j && i!=l && i!=t && i!=y && i!=z && i!=k && i!=u && i!=q && i!=w && j!=l && j!=t && l!=t && j!=y && l!=y && t!=y && j!=z && l!=z && t!=z && y!=z && j!=k && l!=k && t!=k && y!=k && z!=k && j!=u && l!=u && t!=u && y!=u && z!=u && k!=u && j!=q && l!=q && t!=q && y!=q && z!=q && k!=q && u!=q && j!=w && l!=w && t!=w && y!=w && z!=w && k!=w && u!=w && q!=w){
                                                    long long sum=(a[i] & a[j] & a[l] & a[t] & a[y] & a[z] & a[k] & a[u] & a[q] & a[w]);
                                                    if(maxx<sum){
                                                        maxx=sum;
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
        cout<<maxx;
    }
    return 0;
}
