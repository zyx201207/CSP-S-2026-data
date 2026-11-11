#include <bits/stdc++.h>
namespace std
int main(){
    freopen(and.in);
    freopen(and.out);
    int a,n;
    int sum=0;
    cin >>a;
    for(int i=1;i<=a;i++){
        cin>>n; 
        while(n!=0){
            n=n/2;
            if(n=1){
                sum+=n;
            }
        }
    }       
    cout << sum;
    freclose(and.in);
    freclose(and.out);
    return 0;
}
