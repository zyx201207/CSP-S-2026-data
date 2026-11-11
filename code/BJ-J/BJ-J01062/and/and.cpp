#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int mx=-1;
    for (int i=0;i<n;i++)cin>>a[i];
    if(m==1){
        for (int i=0;i<n;i++)mx=max(mx,a[i]);
        cout<<mx;
    }
    if(m==2){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                if(j==i)continue;
                mx=max(mx,(a[i]&a[j]));
            }
        cout<<mx;
    }
    if(m==n){
        mx=a[0];
        for (int i=1;i<n;i++)mx=(mx&a[i]);
        cout<<mx;
    }
    if(m==3){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for(int z=0;z<n;z++)
                    {
                    if(j==i||j==z||i==z)continue;
                    mx=max(mx,(a[i]&a[j]&a[z]));
                }
        cout<<mx;
    }
    if(m==4){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for(int z=0;z<n;z++)
                    for (int b=0;b<n;b++)
                    {
                    if(j==i||j==z||i==z||i==b||j==b||z==b)continue;
                    mx=max(mx,(a[i]&a[j]&a[z]&a[b]));
                }
        cout<<mx;
    }
    if(m==5){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for(int z=0;z<n;z++)
                    for (int b=0;b<n;b++)
                        for (int c=0;c<n;c++)
                    {
                    if(j==i||j==z||i==z||i==b||j==b||z==b||i==c||j==c||z==c||b==c)continue;
                    mx=max(mx,(a[i]&a[j]&a[z]&a[b]&a[c]));
                }
        cout<<mx;
    }
    if(m==6){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for(int z=0;z<n;z++)
                    for (int b=0;b<n;b++)
                        for (int c=0;c<n;c++)
                            for (int d=0;d<n;d++)
                    {
                    if(j==i||j==z||i==z||i==b||j==b||z==b||i==c||j==c||z==c||b==c||i==d||j==d||z==d||c==d||b==d)continue;
                    mx=max(mx,(a[i]&a[j]&a[z]&a[b]&a[c]&a[d]));
                }
        cout<<mx;
    }
    if(m==7){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for(int z=0;z<n;z++)
                    for (int b=0;b<n;b++)
                        for (int c=0;c<n;c++)
                            for (int d=0;d<n;d++)
                                for (int e=0;e<n;e++)
                    {
                    if(j==i||j==z||i==z||i==b||j==b||z==b||i==c||j==c||z==c||b==c||i==d||j==d||z==d||c==d||b==d||i==e||j==e||z==e||b==e||c==e||d==e)continue;
                    mx=max(mx,(a[i]&a[j]&a[z]&a[b]&a[c]&a[d]&a[e]));
                }
        cout<<mx;
    }
    if(m==8){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for(int z=0;z<n;z++)
                    for (int b=0;b<n;b++)
                        for (int c=0;c<n;c++)
                            for (int d=0;d<n;d++)
                                for (int e=0;e<n;e++)
                                    for (int f=0;f<n;f++)
                    {
                    if(j==i||j==z||i==z||i==b||j==b||z==b||i==c||j==c||z==c||b==c||i==d||j==d||z==d||c==d||b==d||i==e||j==e||z==e||b==e||c==e||d==e||i==f||j==f||z==f||b==f||c==f||d==f||e==f)continue;
                    mx=max(mx,(a[i]&a[j]&a[z]&a[b]&a[c]&a[d]&a[e]&a[f]));
                }
        cout<<mx;
    }
    return 0;
}
