#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 50;
int n, a[maxn], cnt;
long long m;
double tmp;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        tmp += a[i];
    }
    tmp /= n * 1.0;
    if(tmp - int(tmp) >= 0.5){
        tmp -= (tmp-int(tmp));
    }else{
        tmp += 1-(tmp-int(tmp));
    }
    sort(a + 1, a + n + 1);
    int j = 1;
    while(m > 0){
        if(a[j] <= tmp && m >= tmp - a[j]){
            //cout << tmp-a[j] << " ";
            m -= tmp-a[j];
            cnt ++;
        }
        if(a[j+1] == tmp && m ==0) {
            m ++;
        }

        j++;
    }
    //cout << endl;
    cout << cnt - 1;
    return 0;
}//ctystal