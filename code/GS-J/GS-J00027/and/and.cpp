#include<bits/stdc++.h>
using namespace std;
int n = 0;
int m = 0;
int mx = 0;
long long a[100];
long long b[100];
int main () {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i = 1;i <= n;i++){
        cin>>a[i];
    }
    b[1] = a[1];
    for(int i = 2;i <= n;i++){
        b[i] = a[i] and a[i-1];
    }
    int i = 1;
    mx = b[i];
    do{
        i++;
        if (b[i] >= mx){
            mx = b[i];
        }
    }while(i >= n);
        cout<<mx<<endl;
return 0;
}
