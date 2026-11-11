#include<bits//stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int e=0;
    int r=0;
    int t=0;
    int a[500005]={};
    int f[300005]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        f[i]=a[i];
    }
    for(int j=0;j<n;j++){
        for(int p=0;p<n-j;p++){
            if(a[p]==f[f.size()-j]){
                t++;
            }
            if(a[p]==f[f.size()-j]){
                r++;
            }
            if(a[p]==f[f.size()-j-2]){
                e++;
            }
        }

    }
    cout<<e<<" "<<r<<" "<<t;


    return 0;
}
