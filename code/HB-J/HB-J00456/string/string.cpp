#include<iostream>
using namespace std;
typedef long long ll;
ll num = 0,ans = 0,k = 0,m,n
ll a[1000001],char x[100001]
ll b[1000001],char[1000001]
ll qv[1000001]
string s;

int cmain(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
         cin >> a[i] > x[i];
         qv[i] = num;
         num += a[i];
    }
qv[n+1] = num ;
num = (num+1)/2;

    return 0;
}
