#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[100];
    int n,m;
    int al=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<m;j++){
            al=a[0] and a[j+1];
        }

    }
    return 0;

}
