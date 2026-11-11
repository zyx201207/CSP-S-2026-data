#include<bits/stdc++.h>
using namespace std;
struct A{
    char c;string s;
};
A a[1000000005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum1=0;
    for(int i=0;i<n;i++){

    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(a[i].c!=a[j].c){
                sum1++;
            }
        }
    }
    cout<<sum1;
    return 0;
}
