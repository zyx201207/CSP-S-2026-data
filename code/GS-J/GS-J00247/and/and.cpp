#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",std::in);
    freopen("travel.out","w",std::out);
    int n,m,sum=0;
    cin>>n>>m;
    int w[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(w[j]<w[j+1]){
                w[j]=w[j]^w[j+1];
                w[j]=w[j]^w[j+1];
                w[j+1]=w[j]^w[j+1];
            }
        }
    }
    sum=w[0];
    for(int i=0;i<m;i++)sum=w[i]&sum;
    cout<<sum;
    return 0;
}