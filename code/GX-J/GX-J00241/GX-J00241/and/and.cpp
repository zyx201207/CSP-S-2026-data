#include<bits/stdc++.h>
using namespace std;

long long a[100005],b[1000005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,k=1,c = 1,ans=0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        k++;
    }
    sort(a+1,a+k+1,greater<int>());
    //for(int i = 1;i <= n;i++){
        //int j = a[i];
        //while(j > 0){
            //b[i] += (a[i]%2) * c;
            //c*=10;
            //a[i] /= 2;
        //}
    //}
    ans = (a[n] && a[n-1]);
    if(m-n+2 > 0)
        for(int i = n-2;i > m;i--){
            ans = ans && a[i];
        }
    cout << ans <<endl;
    return 0;
}
