#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if(m==3){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    ans=max(ans,a[i]&a[j]&a[k]);
    }
    else if(m==4){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        ans=max(ans,a[i]&a[j]&a[k]&a[l]);
    }
    else if(m==5){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]);
    }
    else if(m==6){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
    }
    else if(m==7){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
    }
    else if(m==8){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]);
    }
    else if(m==9){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
    }
    else if(m==10){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]);
    }
    else if(m==11){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]);
    }
    else if(m==12){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]);
    }
    else if(m==13){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        for(int w=1;w<=n;w++)
                                                            ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]);
    }
    else if(m==14){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        for(int w=1;w<=n;w++)
                                                            for(int x=1;x<=n;x++)
                                                                ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]);
    }
    else if(m==15){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        for(int w=1;w<=n;w++)
                                                            for(int x=1;x<=n;x++)
                                                                for(int y=1;y<=n;y++)
                                                                    ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y]);
    }
    else if(m==16){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        for(int w=1;w<=n;w++)
                                                            for(int x=1;x<=n;x++)
                                                                for(int y=1;y<=n;y++)
                                                                    for(int z=1;z<=n;z++)
                                                                        ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]);
    }
    else if(m==17){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        for(int w=1;w<=n;w++)
                                                            for(int x=1;x<=n;x++)
                                                                for(int y=1;y<=n;y++)
                                                                    for(int z=1;z<=n;z++)
                                                                        for(int b=1;b<=n;b++)
                                                                            ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]);
    }
    else if(m==18){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        for(int w=1;w<=n;w++)
                                                            for(int x=1;x<=n;x++)
                                                                for(int y=1;y<=n;y++)
                                                                    for(int z=1;z<=n;z++)
                                                                        for(int b=1;b<=n;b++)
                                                                            for(int c=1;c<=n;c++)
                                                                                ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]&a[c]);
    }
    else if(m==19){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        for(int w=1;w<=n;w++)
                                                            for(int x=1;x<=n;x++)
                                                                for(int y=1;y<=n;y++)
                                                                    for(int z=1;z<=n;z++)
                                                                        for(int b=1;b<=n;b++)
                                                                            for(int c=1;c<=n;c++)
                                                                                for(int d=1;d<=n;d++)
                                                                                    ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]&a[c]&a[d]);
    }
    else if(m==20){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        for(int o=l+1;o<=n;o++)
                            for(int p=o+1;p<=n;p++)
                                for(int q=p+1;q<=n;q++)
                                    for(int r=q+1;r<=n;r++)
                                        for(int s=1;s<=n;s++)
                                            for(int t=1;t<=n;t++)
                                                for(int u=1;u<=n;u++)
                                                    for(int v=1;v<=n;v++)
                                                        for(int w=1;w<=n;w++)
                                                            for(int x=1;x<=n;x++)
                                                                for(int y=1;y<=n;y++)
                                                                    for(int z=1;z<=n;z++)
                                                                        for(int b=1;b<=n;b++)
                                                                            for(int c=1;c<=n;c++)
                                                                                for(int d=1;d<=n;d++)
                                                                                    for(int e=1;e<=n;e++)
                                                                                        ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]&a[c]&a[d]&a[e]);
    }
    printf("%d",ans);
    return 0;
}
