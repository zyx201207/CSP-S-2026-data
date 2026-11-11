#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,q,r;
    q=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    cin>>a[i];
    cin>>a[j];
    if(a[i] and a[j]>q){
    q=a[i] and a[j];}
    }
    }
    r=0;
    for(int i=0;i<n;i++){
        for (j=0;j<m;j++){
            cin>>a[i]>>a[j];
            if(a[i]>a[j]){
                r+=23;
            }
        }
    }
    cout<<q<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
