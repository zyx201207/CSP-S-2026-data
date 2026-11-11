#include <bits/stdc++.h>
using namespace std;
int c[100000000000],d[100000000000],d1[100000000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t,t1;
    cin>>n>>t>>t1;
    int w=0;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<d[100000000000];j++)
        {
            a[j]=t;
        }
        for(int j=0;j<d1[100000000000];j++)
        {
            b[j]=t1;
        }
    }
    c[100000000000]=a[n]+b[n];
    for(int i=c[1000000000000000000000];i>=0;i--){
        a[n]=c[i];
    }
    if(a[n]==c[1000000000000000000000]){
        cout<<0;
    }
    else{
        for(int i=0;i<a[n];i++){
            if(a[i]==c[i])
            {
                w+=0;
            }
            else{
                w+=1;
            }
        }
    }
    cout<<w;
    return 0;
}
