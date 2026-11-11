#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int a[500005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int c;
    for(int i=1;i<n;i++){
        int k=a[i]*(i+1);
        int f=k-a[i-1]-a[i];
       if(m-f>=0){
            c=i+1;
            a[i]+=a[i-1];
       }
    }
    cout<<c;
    fclose(stdin);
    fclose(stdout);
return 0;}
