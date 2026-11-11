#include <iostream>
using namespace std;

long long minn=0;
long long n,a[200005],x;
char c[200005];
char f(){
    for (int i = 1; i < n; i++)if (a[i - 1] < x && a[i] >= x)return c[i];
    return c[0];
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> c[i];
        a[i]+=a[i-1];
    }
    for(int i=0;i<a[n-1];i++){
        x = i;
        int o=f();
        x = a[n - 1] - 1 - i;
        int p=f();
        if(o!=p)minn++;
    }
    cout << minn/2;
    return 0;
}
