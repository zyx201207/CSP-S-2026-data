#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m,a[5005],c[5005];
    cin >> n >> m;
    int flag = 1,flag2 = 1,cha;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != i){
            flag = 0;
        }
        if(i == 2){
			cha = a[i] - a[i-1];
 		}
        if(i > 2 && a[i]-a[i-1] != cha){
			flag2 = 0;
		}
    }
    if(flag == 1){
        long long s = sqrt(m);
        if(s*(s+1) <= m){
            s++;
        }
        cout << s+2;
        return 0;
    }
    if(flag2 == 1){
		m /= cha;
		long long s = sqrt(m);
        if(s*(s+1) <= m){
            s++;
        }
        cout << s+2;
        return 0;
	}
    sort(a+1,a+n+1);
    c[1] = 0;
    for(int i = 2;i <= n;i++){
        c[i] = c[i-1] + a[i] - a[i-1];
    }
    long long nmax = -1;
    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            long long sum = 0;
            for(int k = i;k < j;k++){
                sum += (c[j] - c[k]);
            }
            if(sum <= m && j-i+1 > nmax){
                nmax = j-i+1;
            }
        }
    }
    cout << nmax;
    return 0;
}
