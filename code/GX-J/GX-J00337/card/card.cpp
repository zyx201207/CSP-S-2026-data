

#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool b[300005]=0;
int d[300005]=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int p=1;p<=n;p++){
        for(int i=p;i<=n;i++){
            if(b[i]=0){
                b[i]=1;
                d[i]++;
            }
            else {
                for(int j=1;j<i;j++){
                    if(a[j]=a[i]){
                        for(int z=j;z<i;z++){
                            b[z] = 0;
                            d[z]--;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << d[i] << ' ';
    }
    return 0;
}
