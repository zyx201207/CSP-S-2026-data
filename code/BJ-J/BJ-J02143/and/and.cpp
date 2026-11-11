#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=0;i< n;i++){
        cin >> a[i];
    }
    int c=0;
    if(m==1){
        for(int i=0;i<n;i++){
            c=max(c,a[i]);
        }
        cout << c;
        return 0;
    }
    if(m==2){
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(a[i]!=a[j]) c=max(c,(a[i]&a[j]));
                }
        }
        cout << c;
        return 0;
    }
    return 0;
}
