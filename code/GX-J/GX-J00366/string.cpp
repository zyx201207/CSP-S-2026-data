#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,b=0,d=1,sum=0;
    char c[1003];
    cin >> n;
    for (int i=1;i<=n;i++){
        cin>>a;
        b+=a;
        for (int i=d;i<=b;i++){
            cin >> c[i];
        }
        d=b;
    }
    if (n%2!=0){
        for (int i=1;i<=n;i++){
            if (c[i] != c[n-i+1]){
                sum++;
            }
        }
    }else{
        for (int i=1;i<n;i++){
            if (c[i] != c[n-i+1]){
                sum++;
            }
        }
    }
    cout <<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
