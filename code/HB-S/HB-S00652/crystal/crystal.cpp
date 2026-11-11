#include<bits/stdc++.h>
#define kl long long int
using namespace std;
kl n,m,num=-1,sum = 0,x;
int b[500000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;

    const kl n1 = n + 5;
    kl a[n1];

    for(int i = 0;i < n;i ++){
        cin >> x;
        a[i] = x;
        b[x] ++;
    }

    for(int i = 0;i < n;i ++){
        if(b[a[i]] > num) num = b[a[i]];
    }

    for(int i = num - 1;i >= 0,m >= 0;i --){
        for(int j = b[i];j > 0,m >= 0;j --){
            sum++;
            m+=i-num;
        }
    }

    cout << sum/2;
    return 0;
}
