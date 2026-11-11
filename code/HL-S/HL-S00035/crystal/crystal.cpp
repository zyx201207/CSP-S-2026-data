#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b,b1;
long long m,s=1,h,f1=1,f2=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]!=1)f1=0;
        if(max(a[i],a[i+1])-min(a[i],a[i+1]!=a[i+2],a[i+1])-min(a[i+2],a[i+1]))f2=0;
    }
    if(fl){
        while(m){
        s++;
        m-=s;
        cout<<s+1;
        }
    }
    if(f2){
            while(m){
            b=max(a[1],a[2])-min(a[1],a[2]);
            m-=b;
            b1++;
            }
           cout<<b1;

    }



    fclose(stdin);
    fclose(stdout);
    return 0;
}
