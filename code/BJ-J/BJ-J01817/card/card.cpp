#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m;
    int card[500000];
    int ans[300000]={};
    int arr[500000]; int p=0;

    cin >> n >> m;
    for(int i=0;i<n;++i) cin >> card[i];
    for(int i=0;i<n;++i){
        p=0;
        for(int j=i;j<n;++j){
            arr[p++] = card[j];
            for(int k=0;k<p-1;++k){
                 if(arr[k]==card[j])p=k+1;
            }
        }
        for(int j=0;j<p;++j)++ans[arr[j]-1];
    }
    for(int i=0;i<m;++i) printf("%d ",ans[i]);

    return 0;
}
