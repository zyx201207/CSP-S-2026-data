#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005]={};
int b[100005]={};
int r,f;
int main()
{
    cin>>n>>m;
    int sum[m]={0};
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    while(f!=n){
        for(int i=f;i<n;i++){
            int k=a[i];
            for(int j=0;j<n;j++){
                if(b[j]==k){
                    for(int l=j+1;l<r;l++){
                        b[l]=0;
                    }
                    r=j;
                }else{
                    b[r++]=k;
                }
            }
        }
        for(int d=0;d<n;d++){
            if(b[d]==0)break;
            sum[b[d]]++;
        }
    }
    for(int i=0;i<m;i++){
        cout <<sum[i];
    }
    return 0;
}
