#include <bits/stdc++.h>
using namespace std;

int n,z;
int a[100000005];
int b[100000005];
int c[100000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> z;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int cnt=1;
    for(int i=1;i<=n;i++){
            int sum=0;
        for(int j=i;j<=n;j++){
            b[j]+=a[j];
        }
        for(int l=2;l<=n;l++){
            int k=b[1];
            if(a[l]==k){
                for(int m=l;m<=n;m++){
                    c[cnt]=b[m];
                    cnt++;
                }
            }
        }
        for(int p=1;p<=cnt;p++){
            if(c[p]==i){
                sum++;
            }
        }
        cout << sum << " ";
    }
    return 0;
}
