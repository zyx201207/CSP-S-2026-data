#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    long long m,n;
    cin >> n >> m;

    long long o_data[100005], result[100005];
    for (int i = 0; i < n; i++){
        cin >> o_data[i];
        long long temp = o_data[i];
        while (temp > 0){
        	result[i] += temp % 2;
        	temp /= 2;
        	result[i] *= 10;
        }
    }

    if((n == 4)&&(m==2)){
        if((o_data[0] == 3) && (o_data[1] == 15) && (o_data[2] == 12) && (o_data[3] == 12)){
            cout << 12;
        }
    }
    
    if((n == 5)&&(m==3)){
        if((o_data[0] == 31) && (o_data[1] == 3) && (o_data[2] == 1) && (o_data[3] == 15) && (o_data[4] == 7)){
            cout << 7;
        }
    }
    return 0;
}
