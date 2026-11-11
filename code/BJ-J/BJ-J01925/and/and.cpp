#include <iostream>
#include <cstdio>
using namespace std;

int n, m, maxn=-1e9, a[200005];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(m==n)
            maxn&=a[i];
        else if(m==2){
            for(int j=i-1; j>=1; j--)
                maxn=max(a[i]&a[j], maxn);
        }
        else if(m==3){
            for(int j=i-1; j>=2; j--)
                for(int k=j-1; k>=1; k--)
                    maxn=max(a[i]&a[j]&a[k], maxn);
        }
        else if(m==4){
            for(int j=i-1; j>=3; j--)
                for(int k=j-1; k>=2; k--)
                    for(int l=k-1; l>=1; l--)
                        maxn=max(a[i]&a[j]&a[k]&a[l], maxn);
        }
        else if(m==5){
            for(int j=i-1; j>=4; j--)
                for(int k=j-1; k>=3; k--)
                    for(int l=k-1; l>=2; l--)
                        for(int p=l-1; p>=1; p--)
                            maxn=max(a[i]&a[j]&a[k]&a[l]&a[p], maxn);
        }
        else if(m==6){
            for(int j=i-1; j>=5; j--)
                for(int k=j-1; k>=4; k--)
                    for(int l=k-1; l>=3; l--)
                        for(int p=l-1; p>=2; p--)
                            for(int q=p-1; q>=1; q--)
                                maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q], maxn);
        }
        else if(m==7){
            for(int j=i-1; j>=6; j--)
                for(int k=j-1; k>=5; k--)
                    for(int l=k-1; l>=4; l--)
                        for(int p=l-1; p>=3; p--)
                            for(int q=p-1; q>=2; q--)
                                for(int r=q-1; r>=1; r--)
                                    maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r], maxn);
        }
        else if(m==8){
            for(int j=i-1; j>=7; j--)
                for(int k=j-1; k>=6; k--)
                    for(int l=k-1; l>=5; l--)
                        for(int p=l-1; p>=4; p--)
                            for(int q=p-1; q>=3; q--)
                                for(int r=q-1; r>=2; r--)
                                    for(int u=r-1; u>=1; u--)
                                        maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u], maxn);
        }
        else if(m==9){
            for(int j=i-1; j>=8; j--)
                for(int k=j-1; k>=7; k--)
                    for(int l=k-1; l>=6; l--)
                        for(int p=l-1; p>=5; p--)
                            for(int q=p-1; q>=4; q--)
                                for(int r=q-1; r>=3; r--)
                                    for(int u=r-1; u>=2; u--)
                                        for(int v=u-1; v>=1; v--)
                                            maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v], maxn);
        }
        else if(m==10){
            for(int j=i-1; j>=9; j--)
                for(int k=j-1; k>=8; k--)
                    for(int l=k-1; l>=7; l--)
                        for(int p=l-1; p>=6; p--)
                            for(int q=p-1; q>=5; q--)
                                for(int r=q-1; r>=4; r--)
                                    for(int u=r-1; u>=3; u--)
                                        for(int v=u-1; v>=2; v--)
                                            for(int w=v-1; w>=1; w--)
                                                maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w], maxn);
        }
        else if(m==11){
            for(int j=i-1; j>=10; j--)
                for(int k=j-1; k>=9; k--)
                    for(int l=k-1; l>=8; l--)
                        for(int p=l-1; p>=7; p--)
                            for(int q=p-1; q>=6; q--)
                                for(int r=q-1; r>=5; r--)
                                    for(int u=r-1; u>=4; u--)
                                        for(int v=u-1; v>=3; v--)
                                            for(int w=v-1; w>=2; w--)
                                                for(int z=w-1; z>=1; z--)
                                                    maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z], maxn);
        }
        else if(m==12){
            for(int j=i-1; j>=11; j--)
                for(int k=j-1; k>=10; k--)
                    for(int l=k-1; l>=9; l--)
                        for(int p=l-1; p>=8; p--)
                            for(int q=p-1; q>=7; q--)
                                for(int r=q-1; r>=6; r--)
                                    for(int u=r-1; u>=5; u--)
                                        for(int v=u-1; v>=4; v--)
                                            for(int w=v-1; w>=3; w--)
                                                for(int z=w-1; z>=2; z--)
                                                    for(int e=z-1; e>=1; e--)
                                                        maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e], maxn);
        }
        else if(m==13){
            for(int j=i-1; j>=12; j--)
                for(int k=j-1; k>=11; k--)
                    for(int l=k-1; l>=10; l--)
                        for(int p=l-1; p>=9; p--)
                            for(int q=p-1; q>=8; q--)
                                for(int r=q-1; r>=7; r--)
                                    for(int u=r-1; u>=6; u--)
                                        for(int v=u-1; v>=5; v--)
                                            for(int w=v-1; w>=4; w--)
                                                for(int z=w-1; z>=3; z--)
                                                    for(int e=z-1; e>=2; e--)
                                                        for(int f=e-1; f>=1; f--)
                                                            maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e]&a[f], maxn);
        }
        else if(m==14){
            for(int j=i-1; j>=13; j--)
                for(int k=j-1; k>=12; k--)
                    for(int l=k-1; l>=11; l--)
                        for(int p=l-1; p>=10; p--)
                            for(int q=p-1; q>=9; q--)
                                for(int r=q-1; r>=8; r--)
                                    for(int u=r-1; u>=7; u--)
                                        for(int v=u-1; v>=6; v--)
                                            for(int w=v-1; w>=5; w--)
                                                for(int z=w-1; z>=4; z--)
                                                    for(int e=z-1; e>=3; e--)
                                                        for(int f=e-1; f>=2; f--)
                                                            for(int g=f-1; g>=1; g--)
                                                                maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e]&a[f]&a[g], maxn);
        }
        else if(m==15){
            for(int j=i-1; j>=14; j--)
                for(int k=j-1; k>=13; k--)
                    for(int l=k-1; l>=12; l--)
                        for(int p=l-1; p>=11; p--)
                            for(int q=p-1; q>=10; q--)
                                for(int r=q-1; r>=9; r--)
                                    for(int u=r-1; u>=8; u--)
                                        for(int v=u-1; v>=7; v--)
                                            for(int w=v-1; w>=6; w--)
                                                for(int z=w-1; z>=5; z--)
                                                    for(int e=z-1; e>=4; e--)
                                                        for(int f=e-1; f>=3; f--)
                                                            for(int g=f-1; g>=2; g--)
                                                                for(int h=g-1; h>=1; h--)
                                                                    maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e]&a[f]&a[g]&a[h], maxn);
        }
        else if(m==16){
            for(int j=i-1; j>=15; j--)
                for(int k=j-1; k>=14; k--)
                    for(int l=k-1; l>=13; l--)
                        for(int p=l-1; p>=12; p--)
                            for(int q=p-1; q>=11; q--)
                                for(int r=q-1; r>=10; r--)
                                    for(int u=r-1; u>=9; u--)
                                        for(int v=u-1; v>=8; v--)
                                            for(int w=v-1; w>=7; w--)
                                                for(int z=w-1; z>=6; z--)
                                                    for(int e=z-1; e>=5; e--)
                                                        for(int f=e-1; f>=4; f--)
                                                            for(int g=f-1; g>=3; g--)
                                                                for(int h=g-1; h>=2; h--)
                                                                    for(int aa=h-1; aa>=1; aa--)
                                                                        maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e]&a[f]&a[g]&a[h]&a[aa], maxn);
        }
        else if(m==17){
            for(int j=i-1; j>=16; j--)
                for(int k=j-1; k>=15; k--)
                    for(int l=k-1; l>=14; l--)
                        for(int p=l-1; p>=13; p--)
                            for(int q=p-1; q>=12; q--)
                                for(int r=q-1; r>=11; r--)
                                    for(int u=r-1; u>=10; u--)
                                        for(int v=u-1; v>=9; v--)
                                            for(int w=v-1; w>=8; w--)
                                                for(int z=w-1; z>=7; z--)
                                                    for(int e=z-1; e>=6; e--)
                                                        for(int f=e-1; f>=5; f--)
                                                            for(int g=f-1; g>=4; g--)
                                                                for(int h=g-1; h>=3; h--)
                                                                    for(int aa=h-1; aa>=2; aa--)
                                                                        for(int bb=aa-1; bb>=1; bb--)
                                                                            maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e]&a[f]&a[g]&a[h]&a[aa]&a[bb], maxn);
        }
        else if(m==18){
            for(int j=i-1; j>=17; j--)
                for(int k=j-1; k>=16; k--)
                    for(int l=k-1; l>=15; l--)
                        for(int p=l-1; p>=14; p--)
                            for(int q=p-1; q>=13; q--)
                                for(int r=q-1; r>=12; r--)
                                    for(int u=r-1; u>=11; u--)
                                        for(int v=u-1; v>=10; v--)
                                            for(int w=v-1; w>=9; w--)
                                                for(int z=w-1; z>=8; z--)
                                                    for(int e=z-1; e>=7; e--)
                                                        for(int f=e-1; f>=6; f--)
                                                            for(int g=f-1; g>=5; g--)
                                                                for(int h=g-1; h>=4; h--)
                                                                    for(int aa=h-1; aa>=3; aa--)
                                                                        for(int bb=aa-1; bb>=2; bb--)
                                                                            for(int cc=bb-1; cc>=1; cc--)
                                                                                maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e]&a[f]&a[g]&a[h]&a[aa]&a[bb]&a[cc], maxn);
        }
        else if(m==19){
            for(int j=i-1; j>=18; j--)
                for(int k=j-1; k>=17; k--)
                    for(int l=k-1; l>=16; l--)
                        for(int p=l-1; p>=15; p--)
                            for(int q=p-1; q>=14; q--)
                                for(int r=q-1; r>=13; r--)
                                    for(int u=r-1; u>=12; u--)
                                        for(int v=u-1; v>=11; v--)
                                            for(int w=v-1; w>=10; w--)
                                                for(int z=w-1; z>=9; z--)
                                                    for(int e=z-1; e>=8; e--)
                                                        for(int f=e-1; f>=7; f--)
                                                            for(int g=f-1; g>=6; g--)
                                                                for(int h=g-1; h>=5; h--)
                                                                    for(int aa=h-1; aa>=4; aa--)
                                                                        for(int bb=aa-1; bb>=3; bb--)
                                                                            for(int cc=bb-1; cc>=2; cc--)
                                                                                for(int dd=cc-1; dd>=1; dd--)
                                                                                    maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e]&a[f]&a[g]&a[h]&a[aa]&a[bb]&a[cc]&a[dd], maxn);
        }
        else if(m==20){
            for(int j=i-1; j>=19; j--)
                for(int k=j-1; k>=18; k--)
                    for(int l=k-1; l>=17; l--)
                        for(int p=l-1; p>=16; p--)
                            for(int q=p-1; q>=15; q--)
                                for(int r=q-1; r>=14; r--)
                                    for(int u=r-1; u>=13; u--)
                                        for(int v=u-1; v>=12; v--)
                                            for(int w=v-1; w>=11; w--)
                                                for(int z=w-1; z>=10; z--)
                                                    for(int e=z-1; e>=9; e--)
                                                        for(int f=e-1; f>=8; f--)
                                                            for(int g=f-1; g>=7; g--)
                                                                for(int h=g-1; h>=6; h--)
                                                                    for(int aa=h-1; aa>=5; aa--)
                                                                        for(int bb=aa-1; bb>=4; bb--)
                                                                            for(int cc=bb-1; cc>=3; cc--)
                                                                                for(int dd=cc-1; dd>=2; dd--)
                                                                                    for(int ee=dd-1; ee>=1; ee--)
                                                                                        maxn=max(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[z]&a[e]&a[f]&a[g]&a[h]&a[aa]&a[bb]&a[cc]&a[dd]&a[ee], maxn);
        }
    }
    cout << maxn << endl;
}