#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);

    long long n , a[200009] = {} , ans = 0;
    char c[200009] = {};
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }

    long long l , r , ln = 1 , rn = n;
    char ls , rs;
    while(ln <= rn){       //might have some mistake
        if(l == 0){
            l = a[ln];
            ls = c[ln];
            ln++;
        }
        if(r == 0){
            r = a[rn];
            rs = c[rn];
            rn--;
        }
        if(l <= r){
            if(ls != rs){
                ans += l;
            }
            r -= l;
            l = 0;
			//cout << "l small" << l << r << ls << rs << endl << l << r << endl;
        }
        else{
            if(ls != rs){
                ans += r;
            }
            l -= r;
            r = 0;
			//cout << "r small" << l << r << ls << rs << endl << l << r << endl;
        }
    }
    cout << ans;
    return 0;
}
