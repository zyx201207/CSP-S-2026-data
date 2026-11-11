#include<bits//stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int f=0;
    int maxn=0;
    int a[200005]={};
    int z[200005]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<a.size();j++){
        for(int h=0;h<m;h++){
            f=a[j] and a[j+1];
            z[j]=f;
        }
    }
    for(int y=0;y<z.size();y++){
        if(z[y]>z[y+1]){
            maxn=z[y];
        }
        else{
            maxn=z[y+1];
        }
    }
    cout<<maxn;
    return 0;
}
