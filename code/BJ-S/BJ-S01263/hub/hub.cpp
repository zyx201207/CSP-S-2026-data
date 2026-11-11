#include<iostream>
using namespace std;
int main(){
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k,u[500100]={},v[500100]={};
        cin>>n>>k;
        for(int i=1;i<n;i++) cin>>u[i]>>v[i];
        cout<<k-1<<endl;
    }
    return 0;
}