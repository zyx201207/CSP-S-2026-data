#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n],b[n],c[m];
    for(int i=0; i<m;i++)c[i]=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int h=0; h<n-1; h++){
        for(int i=h; i<n; i++){
            for(int j=0; j<n; j++) {
                    if(a[i]==b[j]) for(int k=j+1; k<n; k++) b[k]=0;
                    else b[i]=a[i];
            }
            for(int j=0; j<n; j++) for(int l=1; l<=m; l++) if(b[j]=l) c[j-1]++;
        }
        for(int j=0; j<n; j++) b[j]=0;
    }
    for(int i=0; i<m; i++)cout << c[i] << " ";
    return 0;
}
