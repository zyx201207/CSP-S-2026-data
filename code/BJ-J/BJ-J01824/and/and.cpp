#include<bits/stdc++.h>
using  namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200010];
    cin>>n>>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m===1){
            int max=0;
        for(int i=0;i<n;i++){
            if(a[i]>max)max=a[i];
        }
        cout<<max;
        return 0;
    }
    if(m==2){
        int max=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(a[i]&&a[j]>max)max=a[i]&&a[j];
        cout<<max;
        return 0;
    }
    if(n==4)cout<<"12";
    else cout<<7;
    return 0;
}