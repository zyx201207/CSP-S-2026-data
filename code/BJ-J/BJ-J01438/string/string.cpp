#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],sum;
char a1[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    sum = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> a1[i];
    }
    for(int i = 1,j = n;1;){
        if(a1[i] != a1[j]){
            sum += min(a[i],a[j]);
        }
        if(a[i] > a[j]){
            a[i] -= a[j];
            j--;
        }else if(a[i] < a[j]){
            a[j] -= a[i];
            i++;
        }else{
            i++;
            j--;
        }
        if(i >= j){
            break;
        }
    }
    cout << sum << endl;
    return 0;
}