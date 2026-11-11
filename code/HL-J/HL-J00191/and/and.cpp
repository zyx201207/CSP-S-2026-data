#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,max_1=-INT_MAX;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        if(y>=max_1){
            max_1=y;
        }
    }
    cout<<max_1;



    return 0;
}
