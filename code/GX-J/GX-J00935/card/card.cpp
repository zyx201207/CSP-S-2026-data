
#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
long long b[10000005];
long long c[10000005];
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(b[j]==a[i]){
                for(int l=j;l<=i;l++){
                    b[l]=0;
                }
            }else{
                c[b[j]]++;
            }
        }
        b[i]=a[i];
        c[b[i]]++;
        //for(int f=1;f<=i;f++){
            //c[b[f]]++;
        //}
    }
    for(int i=m;i>=1;i--){
        cout << c[i] << ' ';
    }
    return 0;
}
