#include <iostream>
using namespace std;
int main(){
    ios::sync_with_studio(false);
    cin.(nullptr);
    //freopen("and.in","r");
    //freopen("and.out","w");
    long long n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]<a[j-1])  swap(a[j],a[j-1]);
        }
    }

}
