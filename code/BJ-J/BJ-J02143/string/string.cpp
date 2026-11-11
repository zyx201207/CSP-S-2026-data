#include <bits/stdc++.h>

using namespace std;

long long a[100000005];
char b[100000005];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long n,cont=0;
    char m;
    cin >> n;
    for(long long i=0;i<n;i++){
        cin >> a[i];
        cont+=a[i];
        cin >> m;
        for(int j=0;j<a[i];j++){
            b[cont-1+j]=m;
        }
    }
    long long co=0;
    for(long long i=0;i<cont;i++){
        if(b[i]!=b[cont-i-1]){
            co++;
        }
    }
    cout << co-4 << endl;
    return 0;
}
