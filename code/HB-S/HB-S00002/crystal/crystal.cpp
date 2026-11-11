#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n],t=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        t+=a[i];
        cout<<t<<endl;
        if (t+a[i]/i<a[i]){
            cout<<i;
            return 0;
        }
    }


    return 0;
}
