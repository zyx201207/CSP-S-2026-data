#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,b;
    long long q,a,c[a+10];
    cin >> a >> b;
    for(int i=1;i<=a;i++){
        cin >> c[i];
    }
    for(int i=1;i<=j;i++){
        for(int j=1;j<=a-1;j++){
            if(c[i+1]>c[i]){
                q=c[i];
                c[i]=c[i+1];
                c[i+1]=q;
            }
        }
    }
    cout << c[b];

}

