#include <iostream>
using namespace std;
int a[2000005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=20;k++){
            if(a[i]==pow(2,k)-1){
                cout<<a[i];
                return 0;
            }
        }
    }
    return 0;
}