#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5000010],b[5000010],maxx = 1,sum,num = 1,c = 2;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(long long i = 2;i <= n;i++){
        b[i] = a[i] - a[i - 1];
    }
    for(long long i = 2;i <= n;i++){
        sum += maxx * b[i];
        if(sum > m){
            sum -= maxx * b[i];
            i--;
            for(int j = c;j <= i;j++){
                sum -= b[j];
            }
            c++;
            maxx--;
            num = max(num,maxx);
        }else{
            maxx++;
            num = max(num,maxx);
        }
    }
    num = max(num,maxx);
    cout << num << endl;
    return 0;
}
