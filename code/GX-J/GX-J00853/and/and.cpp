#include <bits/stdc++.h>
using namespace std;
int ui(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
         sort(a+0,a+n,ui);
         cout<<a[0];
         return 0;
    }
    if(m==n){
        int u=a[0]&a[1];
        for(int i=2;i<n;i++){
        u=u&a[2];
    }
        cout<<u;
        return 0;
    }
    if(m==2){
        int max1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and (a[i]&a[j])>max1){
                    max1=a[i]&a[j];
                }
                //cout<<max1<<" ";
            }
            //cout<<endl;
        }
        cout<<max1;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
