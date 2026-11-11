#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e8+5;
char a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll k,l=0,n,cnt=0;
    cin >> n;
    char c;
    while(n--){
        cin >> k >> c;
        for(int i=l,j=1;j<=k;j++,i++){
            a[i]=c;
        }
        l+=k;
    }ll left,right;
    if(l%2==0)left=l/2,right=l/2+1;
    else left=l/2,right=l/2;
    //for(int i=0;i<100000000;i++)if(a[i])cout <<a[i] <<" "<<i<<endl;
    while(left>=0){
            //cout << "m" <<a[left] << "n" << a[right] <<"p\n";
        if(a[left]!=a[right])cnt++;
        --left,++right;
    }cout << cnt;
    return 0;
}
