#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long n,m,cnt=0;
long long l, r;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                l=i;
                r=j;
                break;
            }
        }
    }
    for (int i=l+1;i<=r;i++){
        a[i]=0;
    }
    int c=a[1];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]=c){
                cnt++;
                c++;
            }
        }
        cout << cnt << " ";
    }
    return 0;
}
