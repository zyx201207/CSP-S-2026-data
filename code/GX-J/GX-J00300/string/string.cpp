#include <bits/stdc++.h>
using namespace std;
char a[789512];
char s[444444];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,q,cnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> q >> a[i];
        if(q>=2){
            a[i+1]=a[i];
            i++;
            n++;
        }
    }
    for(int i=n-1;i>=0;i++){
        s[i]=a[i];
    }
    for(int i=0;i<n;i++){
        cout << a[i];
    }
    return 0;
}
